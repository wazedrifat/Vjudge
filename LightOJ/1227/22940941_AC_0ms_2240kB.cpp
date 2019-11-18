//wazed rifat
 
#include<bits/stdc++.h>
using namespace std;
 
#define LLI long long int
 
LLI i,j,n,test,sum,p,q,t,a[35];
 
int main(   )
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
//  freopen("input1.txt","r",stdin);
   
    cin>>test;
   
    for(t=1 ; t<=test ; t++)
    {
        cin>>n>>p>>q;
       
        for(i=0 ; i<n ; i++)
        cin>>a[i];
       
        for(i=0,sum=0 ; i<p&&i<n&&sum+a[i]<=q ; i++)
        sum+=a[i];
       
        printf("Case %d: %d\n",t,i);
       
    }
   
}
 