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

TYP i,j,n,m,test,s,cnt,t,ps,l,dp[2005][2005];
struct itm
{
	TYP sz,vl;
}a[2005];

int main(	)
{
//	READ
	
	cin>>s>>n;
	
	for(i=0 ; i<n ; i++)
	cin>>a[i].sz>>a[i].vl;
	
	memset(dp,0,sizeof dp);
	
	for(j=0 ; j<=s ; j++)
	for(i=0 ; i<n ; i++)
	if(a[i].sz<=j)
	dp[i+1][j]= max( dp[i][j] , dp[i][j-a[i].sz]+a[i].vl);
	else
	dp[i+1][j]=dp[i][j];
	
	cout<<dp[n][s];
}

