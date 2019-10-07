#include<bits/stdc++.h>
using namespace std;

int n, f[400], dp[400], cnt, cur;

int main()
{
    cin>>n;

    for(int i=0 ; i<n ; i++)
	{
		int a;
		cin>>a;
		f[a]=1;
	}

	for(int i=1 ; i<=365 ; i++)
	{
		cur+=f[i];
		dp[i]=dp[i-1]+cur;

		if(dp[i]>=20)
		{
//			cout<<"i="<<i<<" dp[i]="<<dp[i]<<" cur="<<cur<<endl;
			cnt++;
			cur=0;
			dp[i]=cur;
//			cout<<"i="<<i<<" dp[i]="<<dp[i]<<" cur="<<cur<<endl<<endl;
		}
	}

	cout<<cnt+(dp[365]!=0);
}
