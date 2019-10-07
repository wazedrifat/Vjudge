#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	int dp[105][105], y[105], cnt[105];

	int test;
	scanf("%d", &test);

	for(int t=1 ; t<=test ; t++)
	{
		for(int i=0 ; i<=100 ; i++)
		for(int j=0 ; j<=100 ; j++)
			dp[i][j]=0;
		for(int i=0 ; i<=100 ; i++)
			cnt[i]=0;

		int n, w, k, temp;
		scanf("%d %d %d", &n, &w, &k);

		for(int i=1 ; i<=n ; i++)
		scanf("%d %d", &temp, &y[i]);

		sort(y+1, y+n+1);

		for(int i=1 ; i<=n ; i++)
			dp[i][1]=cnt[i]=upper_bound(y+1, y+n+1, y[i] )-lower_bound(y+1, y+n+1, y[i]-w );

//		for(int i=0 ; i<=n ; i++)
//			cout<<cnt[i]<<" ";
//		cout<<endl;

		for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=k ; j++)
		{
			int l=i-cnt[i];
			l=max(0, l);
			dp[i][j]=max(dp[l][j-1]+cnt[i], max(dp[i-1][j], dp[i][j-1]) );
//			cout<<"i="<<i<<" j="<<j<<" l="<<l<<" "<<dp[i][j]<<"="<<dp[l][j-1]+cnt[i]<<", "<<dp[i-1][j]<<", "<<dp[i][j-1]<<endl;
		}

//		for(int i=0 ; i<=n ; i++)
//		{
//			for(int j=0 ; j<=k ; j++)
//				cout<<dp[i][j]<<"\t";
//			cout<<endl;
//		}
		cout<<"Case "<<t<<": "<<dp[n][k]<<endl;
	}
}
