#include <QCoreApplication>
#include<iostream>
#include<cmath>
#include<Matrix.h>


using namespace std;

double func_DET(double &lambda,Matrix A)
  {
    Matrix E(3);
    E.E();
    A=A-E*lambda;
    return A.det();
  }


double root(double C_minus,double C_plus,double (*func)(double&,Matrix),double &eps,Matrix A);


int main()
{
    int n=3;
    double eps =1e-5;


    Matrix A(n);


    A.set(0,0,9);
    A.set(0,1,-2);
    A.set(1,0,-2);
    A.set(0,2,3);
    A.set(2,0,3);
    A.set(1,1,6);
    A.set(1,2,8);
    A.set(2,1,8);
    A.set(2,2,-6);



    double **Otrezok=new double *[n];
    for(int i=0;i<n;i++)
      Otrezok[i]=new double[2];

    Otrezok[0][0]=-11;
    Otrezok[0][1]=-9;
    Otrezok[1][0]=8.5;
    Otrezok[1][1]=9.5;
    Otrezok[2][0]=10;
    Otrezok[2][1]=10.6;

    double*
        lambda=new double[n];

    for(int i=0;i<n;i++)
      {
        lambda[i]=root(Otrezok[i][0],Otrezok[i][1],func_DET,eps,A);

      }

    A.E();
    for(int i=0;i<n;i++)
      {
        A.set(i,i,lambda[i]);
      }


    for(int i=0;i<n;i++)
    {
        cout<<"Eigen Value = "<<lambda[i]<<endl<<"Eigen vector = {  ";
        for(int j=0;j<n;j++)
        {
            cout<<A.get(i,j)<<"  ";
        }
        cout<<"}"<<endl<<endl;
    }




}






double root(double C_minus,double C_plus,double (*func)(double&,Matrix),double &eps,Matrix A)
{

    double x;
  double delta;
    do
     {
       x=-(C_plus-C_minus)/(func(C_plus,A)-func(C_minus,A))*func(C_minus,A)+C_minus;
        if(func(x,A)>0)
        {
            delta=fabs(x-C_plus);
            C_plus=x;
        }
        else
        {
            delta=fabs(x-C_minus);
            C_minus=x;
        }

    }while (fabs(delta)>=eps);
    return x;

}
