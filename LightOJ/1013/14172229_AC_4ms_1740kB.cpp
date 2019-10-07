#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	long long int dp[105][105], y[105], cnt[105], res[105][105];

	int test;
	scanf("%d", &test);

	for(int t=1 ; t<=test ; t++)
	{
		string s1, s2;
		cin>>s1>>s2;
		int l1=s1.length(), l2=s2.length();

		for(int i=0 ; i<=l1 ; i++)
		for(int j=0 ; j<=l2 ; j++)
		dp[i][j]=0;

		for(int i=1 ; i<=l1 ; i++)
		for(int j=1 ; j<=l2 ; j++)
			if(s1[i-1]==s2[j-1])	dp[i][j]=1 + dp[i-1][j-1];
			else					dp[i][j]=max( dp[i-1][j], dp[i][j-1] );

//		for(int i=0 ; i<=l1 ; i++)
//		{
//			for(int j=0 ; j<=l2 ; j++)
//				cout<<dp[i][j]<<" ";
//			cout<<endl;
//		}

		for(int i=0 ; i<=l1 ; i++)
		for(int j=0 ; j<=l2 ; j++)
		res[i][j]=1;

		for(int i=1 ; i<=l1 ; i++)
		for(int j=1 ; j<=l2 ; j++)
			if(s1[i-1]==s2[j-1])			res[i][j]=res[i-1][j-1];
			else if(dp[i-1][j]==dp[i][j-1])	res[i][j]=res[i-1][j]+res[i][j-1];
			else if(dp[i][j]==dp[i-1][j])	res[i][j]=res[i-1][j];
			else if(dp[i][j]==dp[i][j-1])	res[i][j]=res[i][j-1];

		cout<<"Case "<<t<<": "<<l1+l2-dp[l1][l2]<<" "<<res[l1][l2]<<endl;
	}
}
