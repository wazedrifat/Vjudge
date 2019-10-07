#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x, y, c;
	cin>>x>>y>>c;

	if(x+y<c)
	{
		cout<<"Impossible\n";
		return 0;
	}

	int a=min(x, c);

	cout<<a<<" "<<c-a;
}
