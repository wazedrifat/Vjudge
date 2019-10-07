#include<bits/stdc++.h>
using namespace std;

int Set(int MASK,int pos){return MASK=MASK | (1<<pos);}
int reset(int MASK,int pos){return MASK=MASK & ~(1<<pos);}
bool check(int MASK,int pos){return (bool)(MASK & (1<<pos));}
int next_popcount(int n)
{
    int c = (n & -n);
    int r = n+c;
    return (((r ^ n) >> 2) / c) | r;
}

long long int dp[17][(1<<17)], n, a[20][20];

long long int rec(int i, long long int mask)
{
	if(dp[i][mask]!=-1)	return dp[i][mask];

	if(i>=n)	return 0;

	long long int cnt=INT_MIN;
	for(int j=0 ; j<n ; j++)
	if(!check(mask, j))
		cnt=max(cnt, rec( i+1, Set(mask, j) )+a[i][j] );

	return dp[i][mask]=cnt;
}

int main()
{
	int test;
	cin>>test;

	for(int t=1 ; t<=test ; t++)
	{
		cin>>n;

		for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<n ; j++)
			cin>>a[i][j];

		memset(dp, -1, sizeof dp);

		long long int res=rec(0, 0);
		cout<<"Case "<<t<<": "<<res<<endl;
	}
}