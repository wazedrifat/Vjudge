#include<bits\stdc++.h>
using namespace std;
int t,k,m,n,f,c,i;
char ch1='.',ch2='.';
int main()
{
    cin>>t;
    for(k=1;k<=t;k++)
    {
        cin>>m>>n;
        for(i=0,f=0,c=0;i<m*n;i++)
        {
            cin>>ch2;
            if(f==0&&ch1=='*'&&ch2=='*')
            {
                f=1;
                c++;
            }
            else if(f==1&&ch1=='*'&&ch2=='.')
                f=0;
            ch1=ch2;
        }
        if(c==3)
            cout<<"Case "<<k<<": Eight"<<endl;
        else
            cout<<"Case "<<k<<": Zero"<<endl;
    }
}
