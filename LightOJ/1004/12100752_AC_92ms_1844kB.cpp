//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define TYP int
#define U unsigned int
#define PI 2.0*acos(0.0)
#define PII pair<int,int>
#define READ freopen("input1.txt","r",stdin);
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS 1e-9
#define DIS(x1,y1,x2,y2) sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) )

TYP i,j,n,test,t,k,a[200][200];

int main(	)
{
//	READ
	
	scanf("%d",&test);
	
	for(t=1 ; t<=test ; t++)
	{
		scanf("%d",&n);
		
		for(i=0,k=1 ; i<2*n-1 ; i++)
		{
			for(j=0 ; j<k ; j++)
			{
				scanf("%d",&a[i][j]);
				
				if(i==0)	continue;
				
				if(i<n && j==0)
				a[i][0]+=a[i-1][0];
				else if(i<n && j==k-1)
				a[i][j]+=a[i-1][j-1];
				else if(i<n)
				a[i][j]+=max( a[i-1][j-1] , a[i-1][j] );
				else
				a[i][j]+=max( a[i-1][j] , a[i-1][j+1] );
			}
		//	cout<<k<<endl;
			
			if(i<n-1)
			k++;
			else k--;
		}
		
		printf("Case %d: %d\n",t,a[2*n-2][0]);
	}
}

