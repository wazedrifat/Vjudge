#include<bits/stdc++.h>
using namespace std;
long long int n,x,i,y,a=0,b=0;
int main()
{
    cin>>n;
    cin>>x;
    for(i=2,a=0;i<=n;i++)
    {
        cin>>y;
        //cout<<"b+y="<<b+y<<" a="<<a;
        if((y>=x)||(x>y&&x-y<=b))
        {
            x=y;
            b=0;
            continue;
        }
        if(b+y<x)
        {
            a+=x-b-y;
            b+=x-b-y;
        }

        //cout<<"a="<<a<<" x="<<x<<"b="<<b<<endl;
    }
    cout<<a;
}
