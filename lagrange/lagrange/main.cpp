#include <QCoreApplication>
#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

double func(double &x);



double lagrange(double (*func)(double &), double *Arr, double &x);



int main()
{

    int N=100;

    double *p =new double[4];
    p[0]=0.1;
p[1]=0.5;
p[2]=0.9;
p[3]=1.3;

double eps=(p[3]-p[0])/N;
double x=p[0];

ofstream file;
file.open("data1.txt");
while(x<=p[3])
{
    file<<x<< "\t"<<lagrange(func,p,x)<<endl;
    x+=eps;
}
file.close();


double Xour=0.8;
cout<< fabs(func(Xour)-lagrange(func,p,Xour))<<endl;

delete[] p;
}


double func(double &x)
{
    return log(x)+x;
};

double lagrange(double (*func)(double &), double *Arr, double &x)
{
    double SOLUTION=0;
    double PROIZ;
    for(int i=0;i<4;i++)
    {
        PROIZ=1;
        for(int j=0;j<4;j++)
        {
            if(j!=i)
            {
            PROIZ*=(x-Arr[j])/(Arr[i]-Arr[j]);
            }
        }
        SOLUTION+=PROIZ*func(x);
    }
    return SOLUTION;
};
