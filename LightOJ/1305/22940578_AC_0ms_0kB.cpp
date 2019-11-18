//wazed rifat
 
#include<bits/stdc++.h>
using namespace std;
 
#define D double
 
int t,test;
D ax,ay,bx,by,cx,cy,dx,dy,a,b,c,s,sum;
 
D dis(D x1,D y1,D x2,D y2)
{
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}
 
int main(   )
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   
    scanf("%d",&test);
   
    for(t=1 ; t<=test ; t++)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&cx,&cy);
       
        dx=ax+(cx-bx);
        dy=ay+(cy-by);
       
        a=dis(ax,ay,bx,by);
        b=dis(ax,ay,dx,dy);
        c=dis(bx,by,dx,dy);
        s=(a+b+c)/2.0;
        sum=sqrt(s*(s-a)*(s-b)*(s-c));
       
        printf("Case %d: %.0lf %.0lf %.0lf\n",t,dx,dy,2.0*sum);
    }
   
}