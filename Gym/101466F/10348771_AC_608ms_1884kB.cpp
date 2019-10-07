#include<bits\stdc++.h>
using namespace std;
long int n,i,f=0,a,b,c,temp,s;
int main()
{
    cin>>n;
    for(i=0,f=0;i<n;i++)
    {
        cin>>a>>b>>c;
        temp=max(a,max(b,c));
        s=a+b+c-temp;
        if(temp>=s)
            f=1;
    }
    if(f==0)
        cout<<"YES";
    else
        cout<<"NO";
}
