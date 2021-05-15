#include <QCoreApplication>
#include<iostream>
#include<cmath>
#include<Matrix.h>


using namespace std;



int main()
{
    int n=4;


   Matrix A(n);
    A.set(0,0,-4);
    A.set(0,1,-9);
    A.set(0,2,4);
    A.set(0,3,3);

    A.set(1,0,2);
    A.set(1,1,7);
    A.set(1,2,9);
    A.set(1,3,8);

    A.set(2,0,4);
    A.set(2,1,-4);
    A.set(2,2,0);
    A.set(2,3,-2);

    A.set(3,0,-8);
    A.set(3,1,5);
    A.set(3,2,2);
    A.set(3,3,9);

    double *B=new double[n];
    B[0]=-51;
    B[1]=76;
    B[2]=26;
    B[3]=-73;

    double *X=new double[n];




    double max=A.get(0,0);
    int i_max;
    for(int j=0;j<n;j++)
    {
        i_max=j;
        for(int i=j;i<n;i++)
        {
            if(fabs(A.get(i,j))>fabs(max))
            {
                max=A.get(i,j);
                i_max=i;
            }
        }




    if(i_max!=j){
        for(int k=j;k<n;k++)
        {
            double a=A.get(i_max,k);
            A.set(i_max,k,A.get(0,k));
            A.set(0,k,a);
        }

        B[i_max]+=B[0];
        B[0]=B[i_max]-B[0];
        B[i_max]-=B[0];
}


        for(int k=j;k<n;k++)
        {
            double Al=A.get(k,j);
            for(int l=j;l<n;l++)
            {
                double a;
                a=A.get(k,l)/Al;
                A.set(k,l,a);
            }
            B[k]*=1./Al;

        }

        if(j<n-1)
        {


            for(int k=j+1;k<n;k++)
            {
                for(int l=j;l<n;l++)
                {
                   double a=A.get(k,l)-A.get(j,l);
                   A.set(k,l,a);

                }
                B[k]-=B[j];

            }
        }


    }



    //FIND X
    for(int i=0;i<n;i++)
        X[i]=B[i];

    for(int i=n-2;i>=0;i--)
    {
        for(int j=i+1;j<n;j++)
        {
            X[i]-=A.get(i,j)*X[j];
        }
    }




    for(int i=0;i<n;i++)
    {
        cout<<X[i]<<endl;
    }

}
