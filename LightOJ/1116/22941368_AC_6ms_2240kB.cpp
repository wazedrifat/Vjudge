//wazed rifat
 
#include<bits/stdc++.h>
using namespace std;
 
long long int test,t,n,i,f;
 
int main(   )
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin>>test;
   
    for(t=1; t<=test ; t++)
    {
        cin>>n;
       
        i=1;
       
        while(n%2==0)
        {
            n/=2;
           
            i*=2;
        }
       
        if(i%2==0 && n%2==1)
        printf("Case %lld: %lld %lld\n",t,n,i);
        else
        printf("Case %lld: Impossible\n",t);
    }
}
 