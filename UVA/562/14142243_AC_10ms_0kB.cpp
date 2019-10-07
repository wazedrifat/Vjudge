#include<bits/stdc++.h>
using namespace std;

#define PII pair<int, int>

int main()
{
	int t;
	bool dp[50005];
	int coin[105];
	scanf("%d", &t);

	while(t--)
	{
		int n, sum=0;
		scanf("%d", &n);

		for(int i=1 ; i<=n ; i++)
		{
			scanf("%d", &coin[i]);
			sum+=coin[i];
		}

		int mid=sum/2;

		for(int i=1 ; i<=mid ; i++)
			dp[i]=0;
		dp[0]=1;

		for(int i=1 ; i<=n ; i++)
		for(int j=mid ; j>=0 ; j--)
			if(coin[i]<=j)	dp[j]|=dp[ j-coin[i] ];

//		cout<<"dp:";
//		for(int i=0 ; i<=mid ; i++)
//			cout<<dp[i]<<" ";
//		cout<<endl;

		for(int i=mid ; i>=0 ; i--)
		if(dp[i])
		{
			printf("%d\n", sum-2*i);
			break;
		}
	}
}
