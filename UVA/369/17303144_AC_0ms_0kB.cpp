#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n=100, r=100, dp[200][200];
	for(int i=1 ; i<=n ; i++)
	{
		dp[i][0]=dp[i][i]=1;
		for(int j=1 ; j<i ; j++)
			dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
	}

	while(cin>>n>>r && (n || r) )
		cout<<n<<" things taken "<<r<<" at a time is "<<dp[n][r]<<" exactly."<<endl;
}
