//wazed rifat
 
#include<bits/stdc++.h>
using namespace std;
 
#define LLI long long int
 
LLI i,j,n,test,sum,ans,cnt,t,k,f[22];
deque<LLI>v;
 
int main(   )
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
//  freopen("input1.txt","r",stdin);
   
    for(i=1,sum=1,f[0]=1 ; sum<=1000000000000000000 ; i++)
    {
        sum*=i;
       
        f[i]=sum;
    }
   
    cin>>test;
   
    for(t=1 ; t<=test ; t++)
    {
        cin>>n;
       
        if(n==0)
        {
            printf("Case %lld: 0!\n",t);
           
            continue;
        }
       
        v.clear();
       
        i=20;
       
        while(n>0 && i>=0)
        {
            for( ; i>=0 ; i--)
            {
                if(f[i]<=n)
                {
                    v.push_front(i);
                    n-=f[i];
                   
                    i--;
                   
                    break;
                }
            }
        }
       
        int l=v.size();
       
        printf("Case %lld: ",t);
       
        if(n!=0 || l<=0)
        {
            printf("impossible\n");
           
            continue;
        }
       
        for(i=0 ; i<l ; i++)
        {
            printf("%lld!",v[i]);
           
            if(i<l-1)
            printf("+");
        }
       
        printf("\n");
    }
}
 