#include<bits/stdc++.h>
using namespace std;

#define PII pair<int, int>

int main()
{
	int t, w, dp[35][1005], cost[35], gold[35], depth[35];
	vector<PII>v;
	int f=0;

	while(scanf("%d %d", &t, &w)!=EOF)
	{
		int n;
		scanf("%d", &n);

		for(int i=1 ; i<=n ; i++)
		{
			scanf("%d %d", &depth[i], &gold[i]);
			cost[i]=3*w*depth[i];
		}

		for(int i=0 ; i<=t ; i++)
			dp[0][i]=0;
		for(int i=0 ; i<=n ; i++)
			dp[i][0]=1;

		for(int i=1 ; i<=t ; i++)
		for(int j=1 ; j<=n ; j++)
			if(cost[j]<=i)	dp[j][i]=max(dp[j-1][i], gold[j]+dp[j-1][ i-cost[j] ]);
			else			dp[j][i]=dp[j-1][i];

		if(f)	printf("\n");
		f=1;

		cout<<dp[n][t]<<endl;

		for(int i=n, j=t ; i>=0 && j>=0 ; )
			if(dp[i][j]==dp[i-1][j])	i--;
			else
			{
				v.push_back( PII(depth[i], gold[i]) );
				j=j-cost[i--];
			}

		cout<<v.size()<<endl;
		for(int i=v.size()-1 ; i>=0 ; i--)
		{
			printf("%d %d\n", v[i].first, v[i].second);
		}
		v.clear();
	}
}
