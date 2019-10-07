#include<bits/stdc++.h>
using namespace std;

int mask(int b)
{
	int res=0, l=1;
	while(b)
	{
		int x=b%10;

		if(x==4 || x==7)
		{
			res+=x*l;
			l*=10;
		}
		b/=10;
	}
	return res;
}

int main()
{
	int a, b;
	cin>>a>>b;

	for(int i=max(a,b) ; ; i++)
		if(i>a && mask(i)==b)
		{
			cout<<i;
			return 0;
		}
}