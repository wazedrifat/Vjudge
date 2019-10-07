//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define INT int
#define MAX 1e8
#define PI 2.0*acos(0.0)
#define PII pair<TYP,TYP>
#define READ freopen("input.txt","r",stdin);
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS 1e-9
#define DIS(x1,y1,x2,y2) sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) )

INT i,j,n,m,test,sum,cnt,t,ps,l,o,ox[1001],ni[1001],co[1001],dp[1001][22][80],k;

int main( )
{
//	READ
	scanf("%d",&t);
	
	while(t--)
	{
//		memset(dp , 1e8 , sizeof dp);
		
		scanf("%d %d %d",&o,&n,&m);
		
		for(i=0 ; i<m ; i++)
		for(j=0 ; j<=o ; j++)
		for(k=0 ; k<=n ; k++)
		dp[i][j][k]=1e8;
		
//		for(i=0 ; i<m ; i++)
//		for(j=0 ; j<=o ; j++)
//		for(k=0 ; k<=n ; k++)
//		if( dp[i][j][k] == 0 && !( j==0 || k==0))
//		cout<<dp[i][j][k]<<"	";
		
		for(i=0 ; i<m ; i++)
		{
			scanf("%d %d %d",&ox[i],&ni[i],&co[i]);
			
			for(j=0 ; j<=o ; j++)
			for(k=0 ; k<=n ; k++)
			{
				if(i==0 && j<=ox[0] && k<=ni[0])	dp[0][j][k]=co[0];
				
				if(j==0 && k==0)
				{
					dp[i][j][k]=0;
					continue;
				}
				
				if(i==0)	continue;
				
				if(j<=ox[i] && k<=ni[i])
				dp[i][j][k]=min(dp[i-1][j][k] , co[i]);
				else
				dp[i][j][k]= min(dp[i-1][j][k] , co[i]+dp[ i-1 ][ max( 0,j-ox[i]) ][ max(0,k-ni[i]) ]);
			}
		}
		
//		for(i=m-1,j=0 ; j<=o ; j++)
//		{
//			for(k=0 ; k<=n ; k++)
//			printf("%d	",dp[i][j][k]);
//		
//			cout<<endl;
//		}
		
		printf("%d\n",dp[m-1][o][n]);
		
	}
}

