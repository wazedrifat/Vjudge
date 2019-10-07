#include<bits/stdc++.h>
using namespace std;
long long int i,ns,n,a=0,b=0,c=0;
int main()
{
    cin>>n;
    char s[n];
    cin>>s;
    ns=strlen(s);
    for(i=0;i<ns;i++)
    if(s[i]=='A')
        a++;
    else if(s[i]=='I')
        b++;
    else
        c++;
    if(b==1)
        cout<<1;
    else if(b>1)
        cout<<0;
    else if(b==0)
        cout<<a;
}
