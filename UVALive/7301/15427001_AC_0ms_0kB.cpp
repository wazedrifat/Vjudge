#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	cin>>test;

	for(int t=1 ; t<=test ; t++)
	{
		int n, m, a[25];
		cin>>n>>m;

		for(int i=0 ; i<n ; i++)
			cin>>a[i];

		sort(a, a+n);

		int total=0, sum=0, cnt=0;
		for(int i=0 ; sum+a[i]<=m && i<n ; i++)
		{
			cnt++;
			sum+=a[i];
			total+=sum;
		}

		cout<<"Case "<<t<<": "<<cnt<<" "<<sum<<" "<<total<<endl;
	}
}
