#include<bits/stdc++.h>
using namespace std;

int dp[(1<<15)], cost[(1<<15)], a[15][15];

bool check(int mask, int pos)
{
	return mask&(1<<pos);
}

int chichinkfak(int mask)
{
	if(!mask)	return 0;
	if(dp[mask]!=-1)	return dp[mask];

	int res=0;
	for(int i=mask ; i ; i=--i&mask)
	{
//		cout<<"rec mask="<<bitset<4>(i^mask)<<"\tcost["<<bitset<4>(i)<<"]="<<cost[i]<<endl;
		if(cost[i]<0)
		{
//			cout<<bitset<4>(i^mask)<<"\t"<<chichinkfak(i^mask)<<"\t"<<cost[i]<<endl;
			res=min(res, chichinkfak(i^mask)+cost[i]);
		}
	}

//	cout<<"mask="<<bitset<4>(mask)<<" res="<<res<<endl;
	return dp[mask]=res;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	int test;
	cin>>test;

	for(int t=1 ; t<=test ; t++)
	{
		int n;
		cin>>n;

		memset(dp, -1, sizeof dp);
		memset(cost, 0, sizeof cost);

		for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<n ; j++)
			cin>>a[i][j];

		for(int i=0 ; i<(1<<n) ; i++)
		{
			for(int j=0 ; j<n ; j++)
			if(check(i, j))
				for(int k=0 ; k<n ; k++)
				if(check(i, k))
					cost[i]+=a[j][k];
//			cout<<"i="<<bitset<4>(i)<<" : "<<cost[i]<<endl;
		}

		cout<<"Case "<<t<<": "<<chichinkfak( (1<<n)-1 )<<endl;
	}
}
