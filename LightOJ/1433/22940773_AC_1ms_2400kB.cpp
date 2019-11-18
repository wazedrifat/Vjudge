//wazed rifat
 
#include<bits/stdc++.h>
using namespace std;
 
#define D double
#define PI acos(-1)
 
D ox,oy,ax,ay,bx,by,r,a,th;
int t,test;
 
D dis(D x1, D y1, D x2, D y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
 
int main(   )
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
//  freopen("input1.txt","r",stdin);
   
    cin>>test;
   
    for(t=1 ; t<=test ; t++)
    {
        cin>>ox>>oy>>ax>>ay>>bx>>by;
       
        r=dis(ox,oy,ax,ay);
        a=dis(ax,ay,bx,by);
       
        th=acos(1-( (a*a)/(2*r*r) ) );
       
        printf("Case %d: %lf\n",t,r*th);
    }
   
}