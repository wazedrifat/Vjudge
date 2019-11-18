#include<bits/stdc++.h>
using namespace std;

int a[200005];

int main()
{
    int n, m, k;
    cin>>n>>m>>k;

    for(int i=0 ; i<n ; i++)
        cin>>a[i];

    int sum=k, cnt=0;
    for(int i=n-1 ; m && i>=0 ;)
    {
        if(a[i]<=sum)
        {
            sum-=a[i--];
            cnt++;
        }
        else
        {
            m--;
            sum=k;
        }
    }
    cout<<cnt;
}