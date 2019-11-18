//wazed rifat
 
#include<bits/stdc++.h>
using namespace std;
#define LLI long long int
 
LLI test,t,i,j,cnt,n,f[32];
 
int main(   )
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
//  freopen("input1.txt","r",stdin);
 
    for(i=1,f[0]=1 ; i<=31 ; i++)
    {
        f[i]=f[i-1]*2;
    }
 
    cin>>test;
   
    for(t=1 ; t<=test ; t++)
    {
        cin>>n;
       
        i=31;
        cnt=0;
       
        while(n)
        {
            if(n>=f[i])
            {
                n-=f[i];
                cnt++;
            }
           
            i--;           
        }
       
        if(cnt%2)
        printf("Case %d: odd\n",t);
        else
        printf("Case %d: even\n",t);
       
    }
   
}
 