//wazed rifat
 
#include<bits/stdc++.h>
using namespace std;
 
#define LLI long long int
 
LLI i,j,n,test,sum,ans,cnt,t,k,r1,r2,c1,c2,f;
 
int main(   )
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
//  freopen("input1.txt","r",stdin);
   
    cin>>test;
   
    for(t=1 ; t<=test ; t++)
    {
        cin>>r1>>c1>>r2>>c2;
       
        if(r1%2==c1%2)
        f=1;
        else
        f=2;
       
        if( (f==1&&r2%2!=c2%2) || (f==2&&r2%2==c2%2) )
        {
            printf("Case %d: impossible\n",t);
           
            continue;
        }
       
        if( r1-c1==r2-c2 || r1+c1==r2+c2 )
            printf("Case %d: 1\n",t);
        else
            printf("Case %d: 2\n",t);
    }
   
}