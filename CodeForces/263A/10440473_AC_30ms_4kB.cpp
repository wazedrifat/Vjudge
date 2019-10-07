#include<bits/stdc++.h>
using namespace std;
int i,j,a,res;
int main()
{
    for(i=1;i<=5;i++)
        for(j=1;j<=5;j++)
        {
            cin>>a;
            if(a==1)
                res=abs(3-i)+abs(3-j);
        }
    cout<<res;
}
