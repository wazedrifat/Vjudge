#include<bits/stdc++.h>
using namespace std;

int r, c, n, x[15], y[15], dp[12][(1<<12)], dis[15][15];

int Set(int MASK,int pos){return MASK=MASK | (1<<pos);}
int reset(int MASK,int pos){return MASK=MASK & ~(1<<pos);}
bool check(int MASK,int pos){return (bool)(MASK & (1<<pos));}

int rec(int i, int mask)
{
	if(__builtin_popcount(mask)==n+1)	return dis[i][0];
	if(dp[i][mask]!=-1)				return dp[i][mask];

	int sum=INT_MAX;
	for(int j=0 ; j<=n ; j++)
	if(!check(mask, j))
		sum=min( sum , dis[i][j]+rec(j, Set(mask, j) ) );

	return sum;
}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		cin>>r>>c>>x[0]>>y[0]>>n;

		for(int i=1 ; i<=n ; i++)
			cin>>x[i]>>y[i];

		memset(dp, -1, sizeof dp);

		for(int i=0 ; i<=n ; i++)
		for(int j=0 ; j<=n ; j++)
			dis[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j]);

		cout<<"The shortest path has length "<<rec(0, 1)<<endl;;
	}
}
