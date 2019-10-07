#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	int test;
	scanf("%d", &test);

	int w[105], p[105], c, dp[10005];
	for(int t=1 ; t<=test ; t++)
	{
		int n, tw;
		cin>>n>>tw;

		for(int i=1 ; i<=n ; i++)
		{
			cin>>p[i]>>c>>w[i];
			tw-=w[i]*c;
		}

//		cout<<"tw="<<tw<<endl;
		memset(dp, 0, sizeof dp);

		for(int j=1 ; j<=n ; j++)
		{
			for(int i=1 ; i<=tw ; i++)
			if(w[j]<=i)	dp[i]=max(dp[i], p[j]+dp[ i-w[j] ]);

//			cout<<"dp "<<j<<" : ";
//			for(int i=0 ; i<=tw ; i++)
//				cout<<dp[i]<<" ";
//			cout<<endl;
		}



		cout<<"Case "<<t<<": ";
		if(tw<0)	cout<<"Impossible"<<endl;
		else		cout<<dp[tw]<<endl;
	}
}

