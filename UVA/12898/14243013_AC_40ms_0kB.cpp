#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long int

bool check(ll MASK,int pos){return (bool)(MASK & ( (ll)1<<pos));}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int test;
	scanf("%d", &test);

	for(int t=1 ; t<=test ; t++)
	{
		ll a, b;
		scanf("%lld %lld", &a, &b);

		ll x=b, y=b;
		for(int i=62 ; i>=0 ; i--)
		if(check(a, i)!=check(b, i))
		{
			x=((ll)1<<(i+1))-1;
			y=~x;
			break;
		}
//		bitset<10>f=b, g=a, m=x, j=y, k=b|x, l=b&y;
//		cout<<f<<endl<<g<<endl<<m<<endl<<j<<endl<<k<<endl<<l<<endl;

		printf("Case %d: %lld %lld\n", t, (b|x), (b&y) );
	}
}
