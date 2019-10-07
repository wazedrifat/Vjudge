#include<bits/stdc++.h>
using namespace std;
long long int t,x,y;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>x;
        y=(4*x*(x+1))/__gcd(4*x,x+1);
        cout<<y/(x+1)+1<<endl;
    }
}
