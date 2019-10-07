#include<bits\stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        if(i<n)
        {
            cout<<"*";
            for(j=1;j<=n-2;j++)
                cout<<" ";
            cout<<"*";
        }
        else
        for(j=1;j<=n;j++)
            cout<<"*";
            cout<<" ";
        if(i>1)
        {
            cout<<"*";
            for(j=1;j<=n-2;j++)
                cout<<" ";
            cout<<"*";
        }
        else
        for(j=1;j<=n;j++)
            cout<<"*";
        cout<<endl;
    }
}
