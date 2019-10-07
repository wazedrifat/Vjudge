#include<bits/stdc++.h>
using namespace std;

bool fn(int n)
{
	int t=3, s1=0, s2=0;
	while(t--)
	{
		s1+=n%10;
		n/=10;
	}
	t=3;
	while(t--)
	{
		s2+=n%10;
		n/=10;
	}

//	cout<<"s1=
	return (s1==s2);
}

int main()
{
	int n;
	cin>>n;

	if( fn(n+1) || fn(n-1) )	cout<<"Yes";
	else						cout<<"No";
}
