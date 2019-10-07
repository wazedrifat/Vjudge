#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int dp[55][1005], cnt[55], taka[55];
	int test;
	scanf("%d", &test);

	for(int t=1 ; t<=test ; t++)
	{
		int n, m;
		scanf("%d %d", &m, &n);

		for(int i=0 ; i<=n ; i++)
			dp[0][i]=0;
		for(int i=0 ; i<=m ; i++)
			dp[i][0]=1;

		for(int i=1 ; i<=m ; i++)
			scanf("%d", &taka[i]);

		for(int i=1 ; i<=m ; i++)
			scanf("%d", &cnt[i]);

		for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=m ; j++)
		{
			dp[j][i]=dp[j-1][i];
			for(int k=1 ; k<=cnt[j] ; k++)
			{
				if(k*taka[j]<=i)	dp[j][i]+=dp[j-1][ i-k*taka[j] ];
				else				break;
				dp[j][i]%=100000007;
			}
		}

		cout<<"Case "<<t<<": "<<dp[m][n]<<endl;
	}

}
