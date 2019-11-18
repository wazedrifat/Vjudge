//wazed rifat
 
#include<bits/stdc++.h>
using namespace std;
 
#define LLI long long int
 
int i,j,n,test,sum,ans,cnt,t,k;
string s;
 
int main(   )
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
//  freopen("input1.txt","r",stdin);
   
    cin>>test;
   
    for(t=1 ; t<=test ; t++)
    {
        sum=0;
       
        cin>>n;
       
        printf("Case %d:\n",t);
       
        while(n--)
        {
            cin>>s;
           
            if(s[0]=='r')   printf("%d\n",sum);
            else
            {
                cin>>k;
               
                sum+=k;
            }
        }
    }
   
}