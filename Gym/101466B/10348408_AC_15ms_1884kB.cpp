#include<bits\stdc++.h>
using namespace std;
unsigned long long int s=1,k=1;
int main()
{
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(i=n-1,s=1,k=1;i>=0;i--)
    {
        k*=a[i];
        s+=k;
        //cout<<k<<" "<<s<<endl;
    }
    cout<<s;
}
