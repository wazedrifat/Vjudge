#include<bits/stdc++.h>
using namespace std;

int BinarySearch(int n, int x)
{
	int l=0, r=x;
	while(l<=r)
	{
		int m=(l+r)/2;
		int s=x*x*x-m*m*m;

		if(s==n)		return m;
		else if(s<n)	r=m-1;
		else			l=m+1;
	}
	return -1;
}

int main()
{
	int n;

	while(cin>>n && n)
	{
		bool f=1;
		for(int i=0 ; f && i<10000 ; i++)
		{
			int b=BinarySearch(n, i);
			if(b>0)
			{
				cout<<i<<" "<<b<<endl;
				f=0;
			}
		}
		if(f)	cout<<"No solution\n";
	}
}
