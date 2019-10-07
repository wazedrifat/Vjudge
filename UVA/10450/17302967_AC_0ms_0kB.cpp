#include<bits/stdc++.h>
using namespace std;

#define MX 100000

long long int dp[MX];

int main()
{
	int test;
	cin>>test;

	dp[1]=2;
	dp[2]=3;

	for(int i=3 ; i<=60 ; i++)
		dp[i]=dp[i-1]+dp[i-2];

	for(int t=1 ; t<=test ; t++)
	{
		int n;
		cin>>n;
		cout<<"Scenario #"<<t<<":"<<endl<<dp[n]<<endl<<endl;

	}
}
