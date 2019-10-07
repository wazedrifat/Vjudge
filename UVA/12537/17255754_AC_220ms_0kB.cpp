#include<bits/stdc++.h>
using namespace std;

long long int x[200005], y[200005], a[200005], b[200005];

long long int fn(long long int cx, long long int cy, long long int i)
{
	long long int t1=cx-x[i];
	long long int t2=cy-y[i];
	return t1*t1+t2*t2;
}

int main()
{

	long long int n, t=1;
	while(cin>>n && n)
	{
		for(long long int i=0 ; i<n ; i++)
			cin>>x[i]>>y[i];

		long long int ax, ay, bx, by, q;
		cin>>ax>>ay>>bx>>by>>q;

		for(long long int i=0 ; i<n ; i++)
		{
			a[i]=fn(ax, ay, i);
			b[i]=fn(bx, by, i);
		}

		sort(a, a+n);
		sort(b, b+n);

		cout<<"Case "<<t++<<":"<<endl;
		while(q--)
		{
			long long int r1, r2;
			cin>>r1>>r2;

			long long int s1=upper_bound(a, a+n, r1*r1)-a;
			long long int s2=upper_bound(b, b+n, r2*r2)-b;
			
			if(n-s1-s2>0)
				cout<<n-s1-s2<<endl;
			else
				cout<<0<<endl;
		}
	}


}
