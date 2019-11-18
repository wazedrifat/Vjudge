//wazed rifat
 
#include<bits/stdc++.h>
using namespace std;
 
long long int t,test,x1,x2,yy1,y2,x,y,n;
 
int main(   )
{
    cin>>test;
   
    for(t=1 ; t<=test ; t++)
    {
        cin>>x1>>yy1>>x2>>y2;
       
        cin>>n;
       
        printf("Case %d:\n",t);
       
        while(n--)
        {
            cin>>x>>y;
           
            if(x>x1 && x<x2 && y>yy1 && y<y2)
            printf("Yes\n");
            else
            printf("No\n");
        }
       
       
    }
   
}
 