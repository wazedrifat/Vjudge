#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, s=0, m=0;
	cin>>n;

	for(int i=0 ; i<n ; i++)
	{
		int x;
		cin>>x;
		s+=x;
		m=max(m, x);
	}
	cout<<s+m;
}
