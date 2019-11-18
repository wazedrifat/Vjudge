#include<bits/stdc++.h>
using namespace std;

#define MX 100005
#define MOD 1000000007
#define ll long long int

int main()
{
	ll t, k, dp[MX];
	cin>>t>>k;

	dp[0]=1;
	for(int i=1 ; i<MX ; i++)
		if(i>=k)	dp[i]=(dp[i-k]+dp[i-1])%MOD;
		else		dp[i]=dp[i-1];

	for(int i=1 ; i<MX ; i++)
		dp[i]=(dp[i]+dp[i-1])%MOD;

	while(t--)
	{
		int a, b;
		cin>>a>>b;

		ll res=dp[b]-dp[a-1];

		if(res<0)	res+=MOD;
		cout<<res<<endl;
	}
}