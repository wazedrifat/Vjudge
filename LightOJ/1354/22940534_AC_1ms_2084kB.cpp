//wazed rifat
 
#include<bits/stdc++.h>
using namespace std;
 
#define LLI long long int
 
LLI j,test,sum,t,a[40],b[40];
 
LLI dec(LLI k)
{
    for(j=1,sum=0 ; k ; j*=2)
    {
        sum+=(k%10)*j;
       
        k/=10;
    }
   
    return sum;
}
 
int main(   )
{
    scanf("%lld",&test);
   
    for(t=1 ; t<=test ; t++)
    {
        scanf("%lld.%lld.%lld.%lld",&a[0],&a[1],&a[2],&a[3]);
        scanf("%lld.%lld.%lld.%lld",&b[0],&b[1],&b[2],&b[3]);
       
        if( a[0]==dec(b[0]) && a[1]==dec(b[1]) && a[2]==dec(b[2]) && a[3]==dec(b[3]) )
        printf("Case %lld: Yes\n",t);
        else
        printf("Case %lld: No\n",t);
    }
   
}
 