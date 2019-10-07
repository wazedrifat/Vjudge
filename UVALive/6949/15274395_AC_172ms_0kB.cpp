#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, a[1005], b[1005];
	while(cin>>n>>m)
	{
		for(int i=0 ; i<n ; i++)
			cin>>a[i]>>b[i];

		while(m--)
		{
			int x, y, t, cnt=0;
			cin>>x>>y>>t;

			for(int i=0 ; i<n ; i++)
			{
				int s=b[i]-a[i], z=0;
				int st=2*s;
				int tm=t%st;

				if(tm>=s)	z=b[i]-(tm-s);
				else		z=a[i]+tm;

				cnt+=(z>=x && z<=y);
			}
			cout<<cnt<<endl;
		}
	}

}
