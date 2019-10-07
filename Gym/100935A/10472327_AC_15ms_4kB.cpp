#include<bits\stdc++.h>
using namespace std;
int t,h1,h2,m1,m2,s1,s2,k;
int main()
{
    cin>>t;
    for(k=1;k<=t;k++)
    {
        cin>>h1>>m1>>s1>>h2>>m2>>s2;
        if(h1*60*60+m1*60+s1==h2*60*60+m2*60+s2)
            cout<<"Case "<<k<<": Yes"<<endl;
        else
            cout<<"Case "<<k<<": No"<<endl;
    }
}
