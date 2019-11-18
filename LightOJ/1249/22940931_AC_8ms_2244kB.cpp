//wazed rifat
 
#include<bits/stdc++.h>
using namespace std;
 
#define LLI long long int
 
LLI i,j,n,test,sum,sum1,sum2,ans,cnt,t,k,r1,r2,c1,c2,f;
string s,str1,str2;
 
int main(   )
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
//  freopen("input1.txt","r",stdin);
   
    cin>>test;
   
    for(t=1 ; t<=test ; t++)
    {
        cin>>n;
       
        cin>>s>>i>>j>>k;
       
        str1=str2=s;
        sum=sum1=sum2=i*j*k;
        n--;
        f=0;
       
        while(n--)
        {
            cin>>s>>i>>j>>k;
           
            cnt=i*j*k;
           
            if(cnt>sum&&sum1<cnt)
            {
                sum1=max(sum1,cnt);
                sum=cnt;
                f=1;
                str1=s;
            }
            else if(cnt<sum&&sum2>cnt)
            {
                f=1;
                sum2=min(sum2,cnt);
                sum=cnt;
                str2=s;
            }
        }
       
        if(f==1)
        cout<<"Case "<<t<<": "<<str1<<" took chocolate from "<<str2<<endl;
        else
        cout<<"Case "<<t<<": no thief"<<endl;
    }
   
}
 
 