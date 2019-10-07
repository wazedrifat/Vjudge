#include<bits/stdc++.h>
using namespace std;
int n,k,i;
int main()
{
    cin>>n>>k;
    long int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    if(k>n)
    {
        cout<<-1;
        return 0;
    }
    else if(k==n)
    {
        cout<<"0 0";
        return 0;
    }
    else
        cout<<a[n-k]<<" "<<a[n-k];

}
