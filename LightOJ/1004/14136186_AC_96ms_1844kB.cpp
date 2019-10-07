#include<bits/stdc++.h>
using namespace std;
 
int i,j,n,test,t,k,a[200][200];
 
int main(   )
{
    scanf("%d",&test);
   
    for(t=1 ; t<=test ; t++)
    {
        scanf("%d",&n);
       
        for(i=0,k=1 ; i<2*n-1 ; i++)
        {
            for(j=0 ; j<k ; j++)
            {
                scanf("%d",&a[i][j]);
               
                if(i==0)    continue;
               
                if(i<n && j==0)
                a[i][0]+=a[i-1][0];
                else if(i<n && j==k-1)
                a[i][j]+=a[i-1][j-1];
                else if(i<n)
                a[i][j]+=max( a[i-1][j-1] , a[i-1][j] );
                else
                a[i][j]+=max( a[i-1][j] , a[i-1][j+1] );
            }
            if(i<n-1)
            k++;
            else k--;
        }
       
        printf("Case %d: %d\n",t,a[2*n-2][0]);
    }
}