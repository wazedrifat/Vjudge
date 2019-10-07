#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, dp[60];
	dp[1]=1;	dp[2]=2;

	for(int i=3 ; i<=50 ; i++)
		dp[i]=dp[i-1]+dp[i-2];

	while(cin>>n && n)
		cout<<dp[n]<<endl;
}
