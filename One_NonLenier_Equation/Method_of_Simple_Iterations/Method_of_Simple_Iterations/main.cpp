#include <QCoreApplication>

#include<cmath>
#include<iostream>
#include<functional>

using namespace std;


double our_func(double& x);




double root(double x1,double x2,double (*func)(double&),double& eps);


int main()
{
    //монотонна от 0.25 до бесконечности
    double x1= 0.25;
    double x2=1.5;
    double eps=1e-5;
    cout<<"root is : "<<root(x1,x2,our_func,eps)<<endl;

}


double our_func(double &x)
{
    return log(1+x)-2*x*x+1;
}


double root(double x1,double x2,double (*func)(double&),double &eps)
{


    double alpha=(func(x2)-func(x1))/(x2-x1);

  double delta;
    do
     {
       delta=func(x1)/alpha;
       x1-=delta;


    }while (fabs(delta)>=eps);
    return x1;

}
