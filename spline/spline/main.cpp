#include <QCoreApplication>
#include"Matrix.h"
#include<functional>
#include<cmath>
#include<iostream>
#include<fstream>
using namespace std;





int main()
{
    function<double(double)> Spline;
    int n=5;


    // значения коодинат и функции в данных 4 точках

    double *X=new double[n];

    X[0]=0.1;
    X[1]=0.5;
    X[2]=0.9;
    X[3]=1.3;
    X[4]=1.7;

    double *y = new double[n];
     y[0]=-2.2026;
     y[1]=-0.19315;
     y[2]=0.79464;
     y[3]=1.5624;
     y[4]=2.2306;



     //Создаем матрицу коэфициетов для ЛНУ
   Matrix A(n,n,0.);
   A.set(0,0,2);
   A.set(1,1,4);
   A.set(2,2,4);
   A.set(3,3,4);
   A.set(4,4,2);
   for(int i=0;i<n-1;i++)
   {
       A.set(i,i+1,1);
       A.set(i+1,i,1);
   }

   //Обратная матрица для нахождения производных в концах отрезка
   Matrix _A(n,n);
   _A=A.rev();

   A.~Matrix();

//for (int i=0;i<n;i++)
//{
//    for(int j=0;j<n;j++)
//       {
//        cout<<_A.get(i,j)<<"   ";
//    }
//    cout<<endl;

//}


// вектор неоднородности ЛНУ
  double *b=new double[n];

  b[0]=3*(y[1]-y[0]);
  b[1]=3*(y[2]-y[0]);
  b[2]=3*(y[3]-y[1]);
  b[3]=3*(y[4]-y[2]);
  b[4]=3*(y[4]-y[3]);


  //создаем вектор производдных z
  double *z=new double[n];

  for(int i=0;i<n;i++)
  {
      z[i]=0;
      for(int j=0;j<n;j++)
      {
          z[i]+=_A.get(i,j)*b[j];
      }
   }


  _A.~Matrix();
  delete [] b;

  //создаем матрицу коэфициентов для решения ур-я B*(вектор из y-ов и z-ов концов отрезка)=(коэфициетны функции на отрезке)

  double **B=new double*[4];
  for(int i=0;i<4;i++)
  {
      B[i]=new double[4];
      if(i<2)
      {

         for(int j=0;j<4;j++)
         {
             if(i==j)
                 B[i][j]=1;
             else
                B[i][j]=0;
         }
      }
      else if(i==2)
      {
          B[i][0]=-3;
          B[i][1]=-2;
          B[i][2]=3;
          B[i][3]=-1;

      }

      else if(i==3)
      {
          B[i][0]=2;
          B[i][1]=1;
          B[i][2]=-2;
          B[i][3]=1;

      }
  }



   //создаем матрицу с кожфициетами для каждой из n-1 функции на отрезках

  double **Coef_a=new double*[n-1];
  for(int i=0;i<n-1;i++)
  {
      Coef_a[i]=new double[4];
      double *vector=new double[4];
      vector[0]=y[i];
      vector[1]=z[i];
      vector[2]=y[i+1];
      vector[3]=z[i+1];

      for(int j=0;j<4;j++)
      {
          Coef_a[i][j]=0;
          for(int k=0;k<4;k++)
          Coef_a[i][j]+=B[j][k]*vector[k];
      }

  }

for(int i=0;i<4;i++)
{
    delete[] B[i];
}
delete [] B;




//Создаем функцию сплайн




  Spline=[Coef_a,X,n](double x){

      int value=1;

          while(X[value]<=x)
          {

              value++;

              if(value==n-1)
              {

                break;
              }
          }
value-=1;

      //сведем отрезок к единичному

      x=(x-X[value])/(X[value+1]-X[value]);

      x=Coef_a[value][0]+Coef_a[value][1]*x+Coef_a[value][2]*x*x+Coef_a[value][3]*x*x*x;
        return x;
  };

//построим график

  int Dots=1600;
  double eps;
  eps=(X[4]-X[0])/Dots;

  ofstream file;
  file.open("data.txt");

  double Coordinate=X[0];
    while(Coordinate<=1.7)
    {
        file<<Coordinate<<"\t"<<Spline(Coordinate)<<endl;
        cout<<Coordinate<<"\t"<<Spline(Coordinate)<<endl;
        Coordinate+=eps;
    }
file.close();

cout<<endl<<"0.8"<<"\t"<<Spline(0.8)<<endl;


//чистим память

for(int i=0;i<n-1;i++)
{
    delete [] Coef_a[i];
}
delete [] Coef_a;


}
