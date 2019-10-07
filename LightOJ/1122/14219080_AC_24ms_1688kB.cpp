#include<bits/stdc++.h>
using namespace std;

#define MX 15

int n, dp[MX][MX], dig[MX], m;

int digit(int prev=-1, int cnt=0)
{
	if(cnt==n)				return 1;
	if(dp[prev+1][cnt]!=-1)	return dp[prev+1][cnt];

	int c=0;
	for(int i=0 ; i<m ; i++)
	if(prev==-1 || abs(dig[i]-prev)<=2)
		c+=digit(dig[i], cnt+1);

	 return dp[prev+1][cnt]=c;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int test;
	cin>>test;

	for(int t=1 ; t<=test ; t++)
	{
		cin>>m>>n;

		for(int i=0 ; i<m ; i++)
			cin>>dig[i];

		for(int i=0 ; i<MX ; i++)
		for(int j=0 ; j<MX ; j++)
			dp[i][j]=-1;

		int res=digit();

		cout<<"Case "<<t<<": "<<res<<endl;
	}
}
