//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define INT int
#define MAX 1<<64
#define MAX3(A,B,C) max(A , max(B , C) )
#define PI 2.0*acos(0.0)
#define PII pair<TYP,TYP>
#define READ freopen("input1.txt","r",stdin);
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS 1e-9
#define DIS(x1,y1,x2,y2) sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) )

INT i,j,n,m,test,sum,cnt,t,ps,l,k;

int main(	)
{
//	READ
	
	scanf("%d %d",&k,&n);
	
	int dp[n+2][k+2],v[n+2],w[n+2];
	
	memset(dp,0,sizeof dp);
	
	for(i=0 ; i<n ; i++)
	{
		scanf("%d %d",&v[i],&w[i]);
		
		for(j=0 ; j<=k ; j++)
		if(w[i]<=j)
		dp[i+1][j]= max (dp[i][j] , v[i]+dp[i][ max(0 , j-w[i])]);
		else 
		dp[i+1][j]=dp[i][j];
		
	}
	
	printf("%d",dp[n][k]);
}

