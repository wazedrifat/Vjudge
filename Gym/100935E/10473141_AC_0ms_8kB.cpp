#include<bits\stdc++.h>
using namespace std;
long int t,k,i,s,a[10],b[5];
int main()
{
    cin>>t;
    for(k=1;k<=t;k++)
    {
        for(i=0,s=0;i<10;i++)
        {
            cin>>a[i];
            s+=a[i];
        }
        s/=4;
        //cout<<s<<endl;
        sort(a,a+10);
        b[2]=s-a[0]-a[9];
        b[4]=a[8]-b[2];
        b[3]=a[9]-b[4];
        b[0]=a[1]-b[2];
        b[1]=s-b[0]-b[2]-b[3]-b[4];
        cout<<"Case "<<k<<":";
        for(i=0;i<5;i++)
            cout<<" "<<b[i];
        cout<<endl;
    }
}
