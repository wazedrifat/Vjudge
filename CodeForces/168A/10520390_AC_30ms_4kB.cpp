#include<bits\stdc++.h>
using namespace std;
int main()
{
    long long int n,x,y,res;
    cin>>n>>x>>y;
    if((n*y)%100==0)
        res=(n*y)/100-x;
    else
        res=(n*y)/100-x+1;
    if(res>0)
        cout<<res;
    else
        cout<<0;

}
