#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;

	int a=0, b=0, c=0;
	while(t--)
	{
		int A, B, C;
		cin>>A>>B>>C;
		a+=A;	b+=B;	c+=C;

		int m=min(a, min(b, c) );

		if(m<30)
			cout<<"NO\n";
		else
		{
			cout<<m<<endl;
			a-=m;
			b-=m;
			c-=m;
		}
	}
}
