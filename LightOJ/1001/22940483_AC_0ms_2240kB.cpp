//wazed rifat
 
#include<bits/stdc++.h>
using namespace std;
 
#define LLI long long int
 
LLI i,j,n,test,sum,ans,cnt,t,k;
 
int main(   )
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
//  freopen("input1.txt","r",stdin);
   
    cin>>test;
   
    for(t=1 ; t<=test ; t++)
    {
        cin>>i;
       
        if(i>10)
        {
            j=i-10;
            i=10;
        }
        else j=0;
       
       
        printf("%lld %lld\n",j,i);
    }
   
}