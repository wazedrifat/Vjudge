//wazed rifat
 
#include<bits/stdc++.h>
using namespace std;
 
int i,j,test,sum,t,l,r,n,a[30][30],m,k,p,b[30],f;
 
int main(   )
{
    cin>>test;
   
    for(t=1 ; t<=test ; t++)
    {
        cin>>n>>m>>k;
       
        for(i=0 ; i<n ; i++)
        {
            for(j=0 ; j<k ; j++)
            cin>>a[i][j];
        }
       
        cin>>p;
       
        for(i=0 ; i<p ; i++)
        cin>>b[i];
       
        sort(b,b+p);
       
        for(i=0,f=1 ; i<n&&f==1 ; i++)
        {
            for(j=0,f=0 ; j<k&&f==0 ; j++)
            {
                if( (a[i][j]>0 && binary_search(b,b+p,a[i][j])) || (a[i][j]<0 && !binary_search(b,b+p,-a[i][j])) )
                {
//                  cout<<a[i][j]<<" "<<binary_search(b,b+p,a[i][j])<<endl;
                    f=1;
                    break;
                }
            }
           
        }
       
        if(f==0)
        printf("Case %d: No\n",t);
        else
        printf("Case %d: Yes\n",t);
       
        for(i=0 ; i<30 ; i++)
        for(j=0 ; j<30 ; j++)
        a[i][j]=0;
    }
   
}
 
 