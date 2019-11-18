#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int test;
    cin>>test;
   
    for(int t=1 ; t<=test ; t++)
    {
        double a, b, c, d;
        cin>>a>>c>>b>>d;
       
        if(a<b) swap(a, b);
       
        double x=a-b+(d*d-c*c)/(a-b);
        x/=2.0;
        double y=a-b-x;
        double h=sqrt( c*c-y*y );
       
        printf("Case %d: %.7lf\n", t, b*h+h*(a-b)/2);
    }
}
 