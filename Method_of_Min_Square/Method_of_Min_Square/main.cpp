#include <QCoreApplication>

#include<cmath>
#include<iostream>
#include<Matrix.h>
#include<functional>

using namespace std;



int main()
{
  int m=1;
  Matrix X(m+1);

/*////////////////////////////////////////////////////// /*/
  int n=6;   //dots of experiment

  double *x_Data=new double[n];
  double *y_Data=new double[n];
  x_Data[0]=-0.7;
  x_Data[1]=-0.4;
  x_Data[2]=-0.1;
  x_Data[3]=0.2;
  x_Data[4]=0.5;
  x_Data[5]=0.8;

  y_Data[0]=-0.7754;
  y_Data[1]=-0.41152;
  y_Data[2]=-0.10017;
  y_Data[3]=0.20136;
  y_Data[4]=0.5236;
  y_Data[5]=0.9273;

  double *A=new double[m+1];

  double *Y=new double[m+1];

  X.set(0,0,m+1);
  for(int i=0;i<m+1;i++)
  {
      Y[i]=0;
      if(i==0)
      {
          for(int k=0;k<n;k++)
          {
            Y[i]+=y_Data[k];
          }
      }
      else
      {
          for(int k=0;k<n;k++)
          {
            Y[i]+=pow(x_Data[k],i)*y_Data[k];
          }
      }

      double summ;
      for(int j=0;j<m+1;j++)
      {
          summ=0;
          if(i==0 && j==0)
              break;
          for(int k=0;k<n;k++)
          {
            summ+=pow(x_Data[k],i+j);
          }
          X.set(i,j,summ);
      }
  }

  X=X.rev();

  for(int i=0;i<m+1;i++)
  {
      for(int j=0;j<m+1;j++)
      {
          A[i]=X.get(i,j)*Y[j];
      }
  }
    X.~Matrix();

    /* function */


function<double(double&)> func;

  func = [A,m](double &x){
          double res=A[0];
          for(int i=1;i<m+1;i++)
          {
              res+=A[i]*pow(x,i);
          }
       return res;
  };

  // grafics build data

  double x=x_Data[0];
  double eps=1e-4;

  while(x<=x_Data[n-1])
  {
      cout<<x<<"\t"<<func(x)<<endl;
      x+=eps;
  }




}
