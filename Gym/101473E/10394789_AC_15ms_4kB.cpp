#include<bits/stdc++.h>
using namespace std;
long long int n,i,j,m;
int main()
{
    cin>>n>>m;
    int x[m+2];
    for(i=0;i<m;i++)
    cin>>x[i];
    if(n==m)
    {
        cout<<"*";
        return 0;
    }
    sort(x,x+m);
    i=1;
    j=0;
    while(i<=n)
    {
        if(x[j]==i&&j<m)
        {
            i++;
            j++;
        }
        else
        {
            cout<<i<<" ";
            i++;
        }
    }
}
