//wazed rifat
 
#include<bits/stdc++.h>
using namespace std;
 
#define LLI long long int
 
LLI i,j,n,test,sum,ans,cnt,t,k,a[3];
 
int main(   )
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
//  freopen("input1.txt","r",stdin);
   
    cin>>test;
   
    for(t=1 ; t<=test ; t++)
    {
        cin>>a[0]>>a[1]>>a[2];
       
        sort(a,a+3);
       
        if(sqrt( a[0]*a[0] + a[1]*a[1] ) == a[2] && a[0]+a[1]>a[2])
        printf("Case %d: yes\n",t);
        else
        printf("Case %d: no\n",t);
    }
   
}