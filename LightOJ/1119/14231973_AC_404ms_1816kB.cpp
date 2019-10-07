#include<bits/stdc++.h>
using namespace std;

int dp[(1<<15)], cost[20][20], n;

int Set(int MASK,int pos){return MASK=MASK | (1<<pos);}
int reset(int MASK,int pos){return MASK=MASK & ~(1<<pos);}
bool check(int MASK,int pos){return (bool)(MASK & (1<<pos));}


int rec(int mask)
{
	if(__builtin_popcount(mask)==n)	return 0;
	if(dp[mask]!=-1)				return dp[mask];

	int cnt=INT_MAX;
	for(int i=0 ; i<n ; i++)
	if(!check(mask, i))
	{
		int sum=cost[i][i];
		for(int j=0 ; j<n ; j++)
		if(check(mask, j))
			sum+=cost[i][j];

		cnt=min(cnt, sum+rec(Set(mask, i) )) ;
		//cout<<"i="<<i<<" sum="<<sum<<" rec="<<rec(Set(mask, i) )<<" mask="<<bitset<3>(mask)<<endl;
	}

	//cout<<" cnt="<<cnt<<" mask="<<bitset<3>(mask)<<endl;
	return dp[mask]=cnt;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int test=1;
	cin>>test;

	for(int t=1 ; t<=test ; t++)
	{
		cin>>n;

		for(int i=0 ; i<(1<<14) ; i++)
			dp[i]=-1;

		for(int i=0 ; i<n ; i++)
		{
			//cout<<"i="<<i<<endl;
			for(int j=0 ; j<n ; j++)
			cin>>cost[i][j];

		}

		//cout<<"ok"<<endl;
//		for(int i=0 ; i<(1<<14) ; i++)
//		{
//			for(int j=0 ; j<14 ; j++)
//			sum[i]+=a[i][j];
//		}

		cout<<"Case "<<t<<": "<<rec(0)<<endl;
		//cout<<endl<<endl;
	}
}
