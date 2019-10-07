#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int n,x,min=9999999999,j=-1,f=0,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        if(min>x)
        {
            f=0;
            min=x;
            j=i;
        }
        else if(min==x)
        f=1;
    }
    if(f==1)
        cout<<"Still Rozdil";
    else
        cout<<j;
}
