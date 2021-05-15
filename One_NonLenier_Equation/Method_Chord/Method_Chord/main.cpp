#include <QCoreApplication>

#include<cmath>
#include<iostream>
#include<functional>

using namespace std;

double our_func(double& x);

 double root(double C_minus,double C_plus,double (*func)(double&),double& eps);

int main()
{
    double *C_minus=new double[2];
    double *C_plus=new double[2];


    //производная примерно 02 равна и монотонна на -1 -- 0.2   и 0.25 -- бесконечность

    C_minus[0]=-0.9;
    C_minus[1]=0.25;
    C_plus[0]=0.2;
    C_plus[1]=1.5;


    double eps=1e-5;

    cout<<"root 1 = "<<root(C_minus[0],C_plus[0],our_func,eps)<<endl;
    cout<<"root 2 = "<<root(C_minus[1],C_plus[1],our_func,eps)<<endl;

    delete [] C_minus;
    delete [] C_plus;
}

double our_func(double &x)
{
    return log(1+x)-2*x*x+1;
}


double root(double C_minus,double C_plus,double (*func)(double&),double &eps)
{

    double x;
  double delta;
    do
     {
       x=-(C_plus-C_minus)/(func(C_plus)-func(C_minus))*func(C_minus)+C_minus;
        if(func(x)>0)
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
