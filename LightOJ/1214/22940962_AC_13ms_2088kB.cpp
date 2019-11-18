//wazed rifat
 
#include<bits/stdc++.h>
using namespace std;
 
#define LLI long long int
 
LLI i,j,test,sum,t,l,r,n;
string s;
 
int main(   )
{
    cin>>test;
   
    for(t=1 ; t<=test ; t++)
    {
        getchar();
       
        cin>>s>>n;
       
        l=s.length();
       
        for(i=0,r=0 ; i<l ; i++)
        {
            if(s[i]=='-')   continue;
           
            r=(r*10+s[i]-'0')%n;
        }
       
        if(r==0)
        printf("Case %d: divisible\n",t);
        else
        printf("Case %d: not divisible\n",t);
    }
   
}