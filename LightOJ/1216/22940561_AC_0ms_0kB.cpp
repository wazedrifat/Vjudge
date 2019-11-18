//wazed rifat
 
#include<bits/stdc++.h>
using namespace std;
 
#define PI (double)acos(-1)
 
int t,test;
double r1,r2,h,p,k;
 
int main(   )
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   
    scanf("%d",&test);
   
    for(t=1 ; t<=test ; t++)
    {
        scanf("%lf%lf%lf%lf",&r1,&r2,&h,&p);
       
        k=r2+(r1-r2)*( (double)p/h );
       
        printf("Case %d: %lf\n",t,PI*h/(r1-r2)*( k*k*k - r2*r2*r2 )/3.0 );
    }
   
}