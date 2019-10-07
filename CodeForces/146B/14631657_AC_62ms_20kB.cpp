#include<bits/stdc++.h>
using namespace std;

int mask(int b)
{
	int res=0, l=1;
//	cout<<"b="<<b<<" ";
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
//	cout<<"res="<<res<<endl;
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
