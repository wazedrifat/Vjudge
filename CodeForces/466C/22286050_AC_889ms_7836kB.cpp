#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll n, sum, a[500000], b[500000];

int main()
{
	cin>>n;

	for(int i=0 ; i<n ; i++)
		cin>>a[i];

	for(int i=1 ; i<n ; i++)
		a[i]+=a[i-1];

	ll t=a[n-1]/3;

	if(t*3!=a[n-1])
	{
		cout<<0;
		return 0;
	}

	for(int i=0 ; i<n-1 ; i++)
	{
		b[i]=b[i-1];
		if(a[i]==t)
			b[i]++;

		if(i!=0 && a[i]==2*t)
		{
			sum+=b[i-1];
//			cout<<i<<" "<<a[i]<<" "<<b[i-1]<<endl;
		}
	}
	cout<<sum;
}