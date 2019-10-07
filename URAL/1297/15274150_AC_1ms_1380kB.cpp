#include<bits/stdc++.h>
using namespace std;

bool dp[1005][1005];
int main()
{
	string s;
	cin>>s;

	int n=s.length();
	for(int i=0 ; i<n ; i++)
	for(int j=0 ; j<=i ; j++)
		dp[i][j]=1;

	for(int i=1 ; i<n ; i++)
	for(int j=0 ; i+j<n ; j++)
	{
		if(s[j]==s[j+i])
		{
			dp[j][j+i]=dp[j+1][j+i-1];
//			cout<<"if		j="<<j<<" "<<s[j]<<" j+i="<<j+i<<" "<<s[j+i]<<" dp["<<j+1<<"]["<<j+i-1<<"]="<<dp[j+1][j+i-1]<<endl;
		}
		else	dp[j][j+i]=0;
//		cout<<"i="<<i<<" j="<<j<<" dp["<<j<<"]["<<j+i<<"]="<<dp[j][j+i]<<endl;
	}

//	for(int i=0 ; i<n ; i++)
//	{
//		for(int j=0 ; j<n ; j++)
//			cout<<dp[i][j]<<" ";
//		cout<<endl;
//	}

	int maxi=1, l=0, h=0;
	for(int i=0 ; i<=n ; i++)
	for(int j=i+1 ; j<=n ; j++)
		if(dp[i][j] && j-i+1>maxi)
		{
			l=i;	h=j;	maxi=j-i+1;
		}

	for(int i=l ; i<=h ; i++)
		cout<<s[i];
	cout<<endl;
//	main();
}
