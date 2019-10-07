#include<bits/stdc++.h>
using namespace std;

class type
{
public:
	int x, y, z;
	type(int a=0, int b=0, int c=0)
	{
		x=a;	y=b;	z=c;
	}
	bool operator<(const type& t)
	{
		return (x==t.x	?	(y<t.y) : (x<t.x) );
	}
};

int main()
{
	int test;
	type p[3005];
	cin>>test;

	for(int t=1 ; t<=test ; t++)
	{
		int n;
		cin>>n;
		n*=3;

		for(int i=0 ; i<n ; i++)
		{
			cin>>p[i].x>>p[i].y;
			p[i].z=i+1;
		}
		sort(p, p+n);

		for(int i=0 ; i<n ; i+=3)
			cout<<p[i].z<<" "<<p[i+1].z<<" "<<p[i+2].z<<endl;
	}
}
