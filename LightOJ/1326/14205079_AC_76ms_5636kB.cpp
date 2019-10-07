#include<bits/stdc++.h>
using namespace std;

#define MX 1005
#define MOD 10056

int ncr[MX][MX], dp[MX];

int main()
{
	for(int i=0 ; i<MX ; i++)
		ncr[i][0]=ncr[i][i]=1;

	for(int i=2 ; i<MX ; i++)
	for(int j=1 ; j<=i ; j++)
		ncr[i][j]=( ncr[i-1][j]+ncr[i-1][j-1] )%MOD;

	dp[0]=1;
	for(int i=1 ; i<=1000 ; i++)
	{
		int res=0;
		for(int j=1 ; j<=i ; j++)
			res=(res+(ncr[i][j]*dp[i-j])%MOD )%MOD;
		dp[i]=res;
	}

	int test;
	cin>>test;

	for(int t=1 ; t<=test ; t++)
	{
		int n;
		cin>>n;
		cout<<"Case "<<t<<": "<<dp[n]<<endl;
	}
}
