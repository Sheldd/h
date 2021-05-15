#include <QCoreApplication>

#include<cmath>
#include<iostream>
#include<functional>
#include<Matrix.h>

using namespace std;


void Func(double const &a,double *X,double*F);

void Jacobian(double *X, Matrix & W);




void root(double const &a,double *X,double& eps);


int main()
{



    double a=3;
    double *X=new double [2];
    X[0]=1.;
    X[1]=2.8;



    double eps=1e-5;
    root(a,X,eps);
    cout<<"firs root:  x1=  "<<X[0]<<endl;
    cout<<"second root:  x2=  "<<X[1]<<endl;
}


void Func(double const &a,double *X,double*F)
{
    F[0]=X[0]*X[0]+X[1]*X[1]-a*a;
    F[1]=X[0]-exp(X[1])+a;
}

void Jacobian(double *X, Matrix & W)
{
    W.set(0,0,2*X[0]);
    W.set(0,1,1.);
    W.set(1,0,2*X[1]);
    W.set(1,1,-exp(X[1]));
}


void root(double const &a,double *X,double& eps)
{

   Matrix W(2);
   double square_delta;
   double *Delta=new double[2];
   do
   {
   square_delta=0;
   Jacobian(X,W);
   W=W.rev();

   double *F=new double[2];

   Func(a,X,F);

   for(int i =0;i<2;i++)
   {
       Delta[i]=0;
       for(int j=0;j<2;j++)
       {
           Delta[i]+=W.get(i,j)*F[j];
           square_delta+=fabs(Delta[i]);
       }
       X[i]-=Delta[i];
   }


   }while(square_delta>=eps);

  /*function <double(void)> f1_x1 , f2_x1,f1_x2,f2_x2;

   f1_x1=[X](){}
   */





}
