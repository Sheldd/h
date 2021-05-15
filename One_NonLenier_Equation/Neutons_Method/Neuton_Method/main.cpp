#include <QCoreApplication>

#include<cmath>
#include<iostream>
#include<functional>

using namespace std;


double our_func(double& x);

double Proiz_our_func(double &x);


double root(double coordinate,double (*func)(double&),double (*Proiz_func)(double&),double& eps);


int main()
{
    //монотонна от 0.25 до бесконечности
    double coordinate= 0.25;
    double eps=1e-5;
    cout<<"root is : "<<root(coordinate,our_func,Proiz_our_func,eps)<<endl;

}


double our_func(double &x)
{
    return log(1+x)-2*x*x+1;
}

double Proiz_our_func(double &x)
{
    if(x==-1)
        throw ;
    else
        return 1./(x+1)-4*x;
}


double root(double coordinate,double (*func)(double&),double (*Proiz_func)(double&),double &eps)
{

   double x=coordinate;
   double delta;
   do
   {
       delta=func(x)/Proiz_func(x);
       x-=delta;
   }while(fabs(delta)>=eps);



    return x;

}
