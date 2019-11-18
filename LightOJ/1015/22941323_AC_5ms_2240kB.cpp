//wazed rifat
 
#include<bits/stdc++.h>
using namespace std;
 
long long int test,t,n,m,sum;
 
int main(   )
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin>>test;
   
    for(t=1; t<=test ; t++)
    {
        cin>>n;
       
        sum=0;
       
        while(n--)
        {
            cin>>m;
           
            if(m>0)
            sum+=m;
        }
       
        printf("Case %d: %lld\n",t,sum);
    }
}
 