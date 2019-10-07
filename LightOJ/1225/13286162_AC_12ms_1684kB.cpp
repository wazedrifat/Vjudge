//wazed rifat
 
#include<bits/stdc++.h>
using namespace std;
 
long long int test,t,l,f,i;
string s;
 
int main(   )
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin>>test;
   
    for(t=1; t<=test ; t++)
    {
        cin>>s;
       
        l=s.length();
       
        for(i=0,f=0 ; i<l/2 && f==0 ; i++)
        {
            if(s[i]!=s[l-1-i])
            f=1;
        }
       
        if(f==0)
        printf("Case %d: Yes\n",t);
        else
        printf("Case %d: No\n",t);
    }
}