//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define TYP long long int
#define U unsigned int
#define PI 2.0*acos(0.0)
#define PII pair<int,int>
#define READ freopen("input1.txt","r",stdin);
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS 1e-9
#define DIS(x1,y1,x2,y2) sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) )

TYP i,j,n,m,test,sum,cnt,t,ps,l,maxx,a[101][101];

int main(	)
{
	cin>>t;
	
	while(t--)
	{
		cin>>n>>m;
		
		for(i=0 ; i<n ; i++)
		{
			for(j=0 ; j<m ; j++)
			{
				cin>>a[i][j];
				
				if(i==0)	continue;
				
				if(j==0)
				a[i][j]+=max(a[i-1][j] , a[i-1][j+1]);
				else if(j==m-1)
				a[i][j]+=max(a[i-1][j-1] , a[i-1][j]);
				else
				a[i][j]+=max(a[i-1][j] , max(a[i-1][j-1] , a[i-1][j+1]) );
			}
		}
		
		for(i=0,maxx=0 ; i<m ; i++)
		maxx=max(maxx , a[n-1][i]);
		
		cout<<maxx<<endl;
	}
}

