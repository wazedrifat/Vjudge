#include<bits/stdc++.h>
using namespace std;

int a[200005],cnt[10005];

int fn()
{
	int mini=INT_MAX, c=INT_MAX, f=0;
	for(int i=0 ; i<=10000 ; i++)
	{
		if(cnt[i]>1)	return 0;

		if( f && cnt[i]==0)	c++;
		else if(cnt[i]==1)
		{
			f=1;
			//cout<<"i="<<i<<" c="<<c<<" mini="<<min(mini, c)<<endl;
			mini=min(mini, c);
			c=1;

		}

	}
	return mini;
}

int main()
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int n;
		scanf("%d", &n);

		for(int i=1 ; i<=n ; i++)
			scanf("%d", &a[i]);

		int q;
		scanf("%d", &q);
		while(q--)
		{
			int l, r;
			scanf("%d %d", &l, &r);

			for(int i=0 ; i<=10000 ; i++)
				cnt[i]=0;

			r=min(r, l+10001);
			int f=0;
			for(int i=l ; !f && i<=r ; i++)
				if(cnt[ a[i] ]==0)		cnt[ a[i] ]++;
				else			f=1;

			if(f)	printf("0\n");
			else	printf("%d\n", fn() );
		}
	}
}
