#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int dp[6][30005];
	int taka[6]={0, 1, 5, 10, 25, 50};

	for(int i=0 ; i<=30000 ; i++)
	dp[0][i]=0;

	for(int i=0 ; i<=5 ; i++)
		dp[i][0]=1;

	for(int i=1 ; i<=30000 ; i++)
	{
		for(int j=1 ; j<=5 ; j++)
		if(taka[j]<=i)
			dp[j][i]=dp[j-1][i]+dp[j][ i-taka[j] ];
		else	dp[j][i]=dp[j-1][i];
	}

	int n;
	while(scanf("%d", &n)!=EOF)
	if(dp[5][n]>1)	cout<<"There are "<<dp[5][n]<<" ways to produce "<<n<<" cents change.\n";
	else			cout<<"There is only 1 way to produce "<<n<<" cents change.\n";
}
