#include<bits/stdc++.h>
using namespace std;

#define MOD 998244353
#define ll long long int

ll dp[2001][2001];

int main()
{
	ll n, m, k;
	cin>>n>>m>>k;

	ll res=m;

	for(int i=0 ; i<k ; i++)
		res=(res*(m-1))%MOD;

//	cout<<"res1="<<res<<endl;
	dp[0][k]=1;
	for(int i=1 ; i<n ; i++)
	{
		dp[i][0]=dp[i][i]=1;
		for(int j=1 ; j<i ; j++)
			dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%MOD;
	}

	res=(res*dp[n-1][k])%MOD;

//	cout<<"res2="<<res<<" dp="<<dp[n-1][k]<<endl;
	cout<<res;
}