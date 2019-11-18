#include<bits/stdc++.h>
using namespace std;
 
#define file freopen("input.txt", "r", stdin);
#define CLOCK printf("time: %lld ms\n",(long long)clock()*1000/CLOCKS_PER_SEC);
 
int main()
{
    int test;
    cin>>test;
   
    for(int t=1 ; t<=test ; t++)
    {
        double n, m;
        char ch;
        cin>>n>>ch>>m;
 
        double rt=m/n;
       
        int cnt=5000;
        double l=0.0, h=400.0, a=0;
       
        while(cnt--)
        {
            a=(l+h)/2.0;
           
            double r=sqrt( a*a*(1.0+rt*rt) )/2.0;
            double theta=acos( (2.0*r*r-rt*rt*a*a) / (2.0*r*r) );
            double sum=2*a+2*r*theta;
           
            if(sum==400.0)            break;
            else if(sum>400)          h=a;
            else                      l=a;
           
//          cout<<"a="<<a<<" r="<<r<<" theta="<<theta<<" sum="<<sum<<endl;
        }
        printf("Case %d: %.7f %.7f\n", t, a, rt*a);
    }
}