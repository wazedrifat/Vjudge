#include<bits/stdc++.h>
using namespace std;

#define MX 10000005

int a[MX];
int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n, l=MX, h=0;
		cin>>n;

		memset(a, 0, sizeof a);
		while(n--)
		{
			int x, y;
			cin>>x>>y;
			a[x]++;	a[y+1]--;
			l=min(l, x);	h=max(h, y+1);
		}

		int sum=0, maxi=0;
		for(int i=l ; i<=h ; i++)
		{
			sum+=a[i];
			maxi=max(maxi, sum);
		}
		cout<<maxi<<endl;
	}
}
