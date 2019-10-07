#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test, dp[105][105];
	cin>>test;

	for(int t=1 ;t<=test ; t++)
	{
		string s;
		cin>>s;

		int len=s.length();
		for(int i=0 ; i<len ; i++)
		for(int j=0 ; j<len ; j++)
			dp[i][j]=0;

		for(int j=2; j<=len ; j++)
		for(int i=0, k=i+j-1 ; k<len ; i++, k++)
			if(s[i]==s[k])	dp[i][k]=dp[i+1][k-1];
			else			dp[i][k]=1+min(dp[i+1][k], dp[i][k-1]);

		cout<<"Case "<<t<<": "<<dp[0][len-1]<<endl;
	}
}
