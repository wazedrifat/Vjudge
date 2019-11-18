//wazed rifat
 
#include<bits/stdc++.h>
using namespace std;
 
#define PI 2*acos(0.0)
 
int t,test;
double r1,r2,r3,a,b,c,s,v,v1,v2,v3;
 
double th( double x , double y , double z )
{
    double n= ( y*y + z*z - x*x)/( 2*y*z );
   
    return acos(n)/(2*PI);
}
 
int main(   )
{
    cin>>test;
   
    for(t=1 ; t<=test ; t++)
    {
        cin>>r1>>r2>>r3;
       
        a=r1+r3;
        b=r1+r2;
        c=r2+r3;
        s=(a+b+c)/2;
       
        v=sqrt(s*(s-a)*(s-b)*(s-c));
       
        v2=PI*r2*r2*th(a,b,c);
        v1=PI*r1*r1*th(c,a,b);
        v3=PI*r3*r3*th(b,a,c);
       
        printf("Case %d: %lf\n",t,v-v1-v2-v3);
    }
   
}
 