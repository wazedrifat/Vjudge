#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin>>n>>m;

	int x=n*2;
	int res=x/m+(x%m>0);
	if(m>=n)	cout<<2;
	else 		cout<<res;
}
