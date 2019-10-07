#include<bits\stdc++.h>
using namespace std;
int a[100000],k;
int power(int p)
{
    long long int res=1;
    for(long int i=0;i<p;i++)
        res*=2;
    return res;
}
int main()
{
    long int s=0,i,t=0,n,j,k,dif;
    cin>>n;
    for(i=1;s+power(i)<n;i++)
    s+=power(i);
    char ch[i];
    s++;
    dif=n-s;
    k=i-1;
    while(dif)
    {
        a[k]=dif%2;
        dif/=2;
        k--;
        //cout<<"arr"<<k+1<<"="<<a[k]<<endl;
    }
    //cout<<endl<<i<<" "<<s<<" "<<dif;
    for(j=0;j<i;j++)
    {
        if(a[j]==0)
            cout<<"A";
        else
            cout<<"B";
    }
}
