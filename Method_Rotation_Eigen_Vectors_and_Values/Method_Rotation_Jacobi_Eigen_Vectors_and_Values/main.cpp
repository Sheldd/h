#include <QCoreApplication>
#include<iostream>
#include<cmath>
#include<Matrix.h>


using namespace std;



int main()
{
    int n=3;
    double eps =1e-5;


   Matrix A(n), U(n,n,0), S(n);
   S.E();

   for (int i=0;i<n;i++)
   {
       S.set(i,i,1);
   }

   A.set(0,0,9);
   A.set(0,1,-2);
   A.set(1,0,-2);
   A.set(0,2,3);
   A.set(2,0,3);
   A.set(1,1,6);
   A.set(1,2,8);
   A.set(2,1,8);
   A.set(2,2,-6);


   double max=A.get(0,1),
      i_0=0,
      j_0=1;


double delta;
   do{
   //FIND MAX ELEMENT IN MATRIX UPPER MAJOR DIOGONAL
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(A.get(i,j)*A.get(i,j)>=max*max)
            {
                max =A.get(i,j);
                i_0=i;
                j_0=j;
            }
        }
    }

    max=0;
    delta=sqrt(2)*A.get(i_0,j_0);

    //FIND ANGLE OF ROTATION

    int etha=1;
    double tg_2phi=2*A.get(i_0,j_0)/(A.get(i_0,i_0)-A.get(j_0,j_0));
    if(tg_2phi<0)
        etha=-1;

    double K=1./sqrt(1+tg_2phi*tg_2phi);

    double
            COS_PHI=sqrt((1+K)/2),
            SIN_PHI=etha*sqrt((1-K)/2);


    U.E();
    U.set(i_0,i_0,COS_PHI);
    U.set(i_0,j_0,-SIN_PHI);
    U.set(j_0,i_0,SIN_PHI);
    U.set(j_0,j_0,COS_PHI);





    //Rotation


    A=U.T()*A*U;
    S=S*U;



   }while(delta>eps);



//output Eigen vectors and values


for(int j=0;j<n;j++)
{
    cout<<"Eigen Value = "<<A.get(j,j)<<endl<<"Eigen vector = {  ";
    for(int i=0;i<n;i++)
    {
        cout<<A.get(i,j)<<"  ";
    }
    cout<<"}"<<endl<<endl;
}



}
