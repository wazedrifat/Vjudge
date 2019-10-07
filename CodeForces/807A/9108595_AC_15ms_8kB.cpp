#include<bits/stdc++.h>
using namespace std;
long long int a,b,c=4127,d=4127,f=0,n;
int main()
{
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		if(f==1)
		continue;
		if(a!=b)
		f=1;
		else if(a>c&&b>d&&f!=1)
		f=2;
		c=a;
		d=b;
	}
	if(f==1)
	cout<<"rated";
	else if(f==2)
	cout<<"unrated";
	else
	cout<<"maybe";
}
