#include <bits/stdc++.h>
using namespace std;
long long int n,i,j,a,k,s,t;
int main()
{
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>n>>k;
		s=(n+1)*k;
		for(j=0;j<n;j++)
		{
			cin>>a;
			s-=a;
		}
		cout<<"Case "<<i<<": "<<s<<endl;
	}
}
