//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define INT int
#define MAX 1<<64
#define MAX3(A,B,C) max(A , max(B , C) )
#define MIN3(A,B,C) min(A , min(B , C) )
#define PI 2.0*acos(0.0)
#define PII pair<INT,INT>
#define READ freopen("input1.txt","r",stdin);
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS 1e-9
#define DIS(x1,y1,x2,y2) sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) )

INT i,j,n,m,test,sum,cnt,t,ps,l,k,f,a[55],b[55],dp[55][55];

void Test()
{
	for(i=0 ; i<=n ; i++)
	{
		for(j=0 ; j<=n ; j++)
		cout<<dp[i][j]<<"	";
		
		cout<<endl;
	}
}

int main(	)
{
//	READ
	cin>>test;
	
	for(t=1 ; t<=test ; t++)
	{
		cin>>n;
		
		for(i=1 ; i<=n ; i++)	cin>>a[i];
		for(i=1 ; i<=n ; i++)	cin>>b[i];
		
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);		
		
		memset(dp,0,sizeof dp);
		
		sum=0;
		for(i=1 ; i<=n ; i++)
		for(j=1 ; j<=n ; j++)
		{
		//	cout<<a[i]<<"&"<<b[j]<<endl;
			if(a[i]>b[j])	dp[i][j]=MAX3(dp[i-1][j-1]+2,dp[i-1][j],dp[i][j-1]);
			else if(a[i]==b[j])	dp[i][j]=MAX3(dp[i-1][j-1]+1,dp[i-1][j],dp[i][j-1]);
			else	dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
		
	//	Test();
		
		printf("Case %d: %d\n",t,dp[n][n]);
	}
}
