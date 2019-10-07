#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long int

ll n=2, m=4, dp[200][(1<<10)][10];

ll rec(int pos, int flag, int prev)
{
//	cout<<"pos="<<pos<<" flag="<<bitset<10>(flag)<<" "<<bitset<10>((1<<n)-1)<<" prev="<<prev<<endl;

	if(pos<0)	return ( flag==((1<<n)-1) );

	ll &d=dp[pos][flag][prev];
	if(d!=-1)	return d;

	d=0;
	if(prev+1<n)	d=rec(pos-1, flag|(1<<(prev+1)), prev+1)%MOD;
	if(prev-1>=0)	d=(d+rec(pos-1, flag|(1<<(prev-1)), prev-1) )%MOD;

//	cout<<"pos="<<pos<<" flag="<<bitset<10>(flag)<<" prev="<<prev<<" dp="<<d<<endl;
	return d;
}

int main()
{
	int t=1;
	cin>>t;

	while(t--)
	{
		ll res=0;
		cin>>n>>m;

		memset(dp, -1, sizeof dp);
		for(int len=m-1 ; len>=n-1 ; len--)
		{
			for(int i=1 ; i<n ; i++)
			res=(res+rec(len-1, (1<<i), i) )%MOD;
//			cout<<"len="<<len<<" res="<<res<<endl;
		}

		cout<<res<<endl;
	}
}
