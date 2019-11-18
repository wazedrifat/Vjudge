//wazed rifat
 
#include<bits/stdc++.h>
using namespace std;
#define LLI long long int
 
LLI test,t,n,x1,x2,y2,z1,z2,X1,X2,Y1,Y2,Z1,Z2,yy1,v;
 
int main(   )
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
//  freopen("input1.txt","r",stdin);
 
    cin>>test;
   
    for(t=1 ; t<=test ; t++)
    {
        cin>>n;
       
        X1=Y1=Z1=-1;
        X2=Y2=Z2=1000;
       
        while(n--)
        {
            cin>>x1>>yy1>>z1>>x2>>y2>>z2;
           
            X1=max(X1,x1);
            Y1=max(Y1,yy1);
            Z1=max(Z1,z1);
           
            X2=min(X2,x2);
            Y2=min(Y2,y2);
            Z2=min(Z2,z2);
           
        }
       
        v=(Z2-Z1)*(Y2-Y1)*(X2-X1);
       
        if(v<0)
        v=0;
       
        printf("Case %d: %d\n",t,v);
       
    }
   
}
 