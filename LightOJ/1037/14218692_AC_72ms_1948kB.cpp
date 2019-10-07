#include<bits/stdc++.h>
using namespace std;

int Set(int MASK,int pos){return MASK=MASK | (1<<pos);}
int reset(int MASK,int pos){return MASK=MASK & ~(1<<pos);}
bool check(int MASK,int pos){return (bool)(MASK & (1<<pos));}

int dp[(1<<16)], n, damage[20][20], health[20];

int bullets(int mask)
{

	if(dp[mask]!=-1)	return dp[mask];

	if(__builtin_popcount(mask)==n)
	{

		return 0;
	}

	int cnt=INT_MAX, dm[20];
	for(int i=0 ; i<n ; i++)
		dm[i]=1;

	for(int i=0 ; i<n ; i++)
	if(check(mask, i))
	for(int j=0 ; j<n ; j++)
		dm[j]=max(dm[j], damage[i][j]);

//		cout<<"for\n";
	for(int j=0 ; j<n ; j++)
	{
		if(!check(mask, j))
		{
			int s=health[j]/dm[j];
			if(health[j]%dm[j])	s++;

			cnt=min(cnt, s+bullets( Set(mask, j) ) );
		}
	}

	//cout<<"mask="<<mask<<" cnt="<<cnt<<endl;
	return dp[mask]=cnt;
}

int main()
{
//	freopen("input.txt", "r", stdin);
	int test;
	cin>>test;

	for(int t=1 ; t<=test ; t++)
	{
		cin>>n;

		for(int i=0 ; i<n ; i++)
			cin>>health[i];

		for(int i=0 ; i<n ; i++)
		{
			string s;
			cin>>s;

			for(int j=0 ; j<n ; j++)
				damage[i][j]=s[j]-'0';
		}

		for(int i=0 ; i<(1<<(n+1)) ; i++)
		dp[i]=-1;

		int res=bullets(0);

//		for(int i=0 ; i<(1<<n) ; i++)
//		{
//			cout<<i<<" : "<<dp[i]<<endl;
//		}
		cout<<"Case "<<t<<": "<<res<<endl;
	}
}
