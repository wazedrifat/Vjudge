#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int test;
    cin>>test;
   
    for(int t=1 ; t<=test ; t++)
    {
        long long int n, r, c;
        cin>>n;
       
        long long int x=(long long int)ceil( sqrt(n) );
        long long int y=x*x;
       
//      cout<<"x="<<x<<" y="<<y<<endl;
       
        if(x&1)
        {  
            if(y-n<x)
            {
                r=x;
                c=y-n+1;
            }
            else
            {
                c=x;
                x--;
                r=n-x*x;
            }
        }
        else
        {
            if(y-n<x)
            {
                c=x;
                r=y-n+1;
            }
            else
            {
                r=x;
                y-=2*(x-1);
                c=n-y+1;
            }
        }
        cout<<"Case "<<t<<": "<<c<<" "<<r<<endl;
    }
}