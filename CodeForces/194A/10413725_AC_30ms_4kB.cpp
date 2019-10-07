#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    if(n*3<=k)
    {
        cout<<0;
        return 0;
    }
    cout<<n-k+n*2;
}
