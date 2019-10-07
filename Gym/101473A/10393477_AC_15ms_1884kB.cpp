#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(b==c&&a!=b)
        cout<<'A';
    else if(a==b&&c!=a)
        cout<<'C';
    else if(a==c&&b!=a)
        cout<<'B';
    else
        cout<<"*";
}
