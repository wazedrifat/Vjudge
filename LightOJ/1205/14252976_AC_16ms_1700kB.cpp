#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll a, b, dp[20][20][2][2];
int A[20], dig[20], h1, h2, lim;

int digit(ll z, int arr[])
{
	memset(arr, 0, sizeof arr);
	if(!z)	return 1;

	int i=0;
	while(z)
	{
		arr[i++]=z%10;
		z/=10;
	}
	return i;
}

ll rec(int pos, int len, int pal=1, int high=1)
{
//	cout<<"pos="<<pos<<" len="<<len<<" pal="<<pal<<" high="<<high<<endl;
	if(pos<0)	return pal;
	if(dp[pos][len][pal][high]!=-1)	return dp[pos][len][pal][high];

	ll cnt=0;
	int hi=high?	A[pos] : 9;

//	cout<<"pos="<<pos<<" len="<<len<<" hi="<<hi<<endl;

	for(int i=0 ; i<=hi ; i++)
	{
		dig[pos]=i;

		if(len==pos && !i)
			cnt+=rec(pos-1, len-1, pal, high&(i==hi));
		else if(pal && pos<(len+1)/2)
			cnt+=rec(pos-1, len, (dig[len-pos]==i), high&(i==hi));
		else if(pos>=(len+1)/2)
			cnt+=rec(pos-1, len, pal, high&(i==hi));
//		cout<<"i="<<" pos="<<pos<<" len="<<len<<" cnt="<<cnt<<endl;
	}
//	cout<<"pos="<<pos<<" len="<<len<<" pal="<<pal<<" high="<<high<<" dp="<<cnt<<endl;
	return dp[pos][len][pal][high]=cnt;
}

int main()
{
//	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int test;
	cin>>test;

	for(int t=1 ; t<=test ; t++)
	{
		memset(dp, -1, sizeof dp);

		ll x, y;
		cin>>x>>y;
		if(x>y)	swap(x, y);
//		cout<<"x="<<x<<" y="<<y<<endl;

		ll res1=0;
		int h=0;
		if(x)
		{
			a=x-1;
			h=digit(a, A);
			res1=rec(h-1, h-1);
		}

		memset(dp, -1, sizeof dp);
		a=y;
		h=digit(y, A);
//		cout<<"b="<<a<<" h="<<h<<endl;
		ll res2=rec(h-1, h-1);

		ll res=res2-res1;
//		cout<<"res1="<<res1<<" res2="<<res2<<" res="<<res<<endl;

		cout<<"Case "<<t<<": "<<res<<endl;
//		bitset<18>b=res;
//		cout<<"bitset="<<b<<endl<<endl;
//		cout<<b<<endl;
//		printf("Case %d: (%lld)%lld = %lld - %lld\n",t,ans, res, res2, res1);
//		cout<<endl;
	}
}

