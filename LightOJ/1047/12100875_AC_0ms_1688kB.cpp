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

TYP i,j,n,m,test,sum,cnt,t,ps,l,dp[3][21];

int main(	)
{
	scanf("%d",&test);
	
	for(t=1 ; t<=test ; t++)
	{
		scanf("%d",&n);
		
		for(i=0 ; i<n ; i++)
		{
			scanf("%d%d%d",&dp[0][i],&dp[1][i],&dp[2][i]);
			
			if(i==0)	continue;
			
			dp[0][i]+=min( dp[1][i-1] , dp[2][i-1]);
			dp[1][i]+=min( dp[0][i-1] , dp[2][i-1]);
			dp[2][i]+=min( dp[0][i-1] , dp[1][i-1]);
		}
		
		sum=min(dp[0][n-1] , min(dp[1][n-1],dp[2][n-1]) );
		
		printf("Case %d: %d\n",t,sum);
		
	}
}

