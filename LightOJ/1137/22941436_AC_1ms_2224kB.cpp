#include<bits/stdc++.h>
using namespace std;
 
#define file freopen("input.txt", "r", stdin);
#define CLOCK printf("time: %lld ms\n",(long long)clock()*1000/CLOCKS_PER_SEC);
 
int main()
{
//  file
    int test, cnt;
    cin>>test;
   
    for(int t=1 ; t<=test ; t++)
    {
        double l, n, c;
        cin>>l>>n>>c;
       
        double _l=l*(1+n*c);
       
//      cout<<"_l="<<_l<<endl;
        cnt=1000;
        double low=0, high=1e5, r=0;
        while(cnt--)
        {
            r=(low+high)/2.0;
           
            double sum=2*r*r - l*l - 2*r*r*cos(_l/r);
           
//          cout<<"sum="<<2*r*r<<"  -   "<<l*l<<"   -   "<<2*r*r*cos(_l/r)<<"   =   "<<sum<<"   r="<<r<<endl;
           
//          if(sum==0)       break;
            if(sum>0)   high=r;
            else             low=r;
        }
       
//      cout<<"r="<<" _h="<r<<<sqrt( r*r - l*l/4 )<<endl;
        double res=r - sqrt( r*r - l*l/4 );
       
        if(!n || !c) res=0;
       
        printf("Case %d: %.7lf\n", t, res);
//      cout<<endl<<endl<<endl<<endl;
    }
}
 