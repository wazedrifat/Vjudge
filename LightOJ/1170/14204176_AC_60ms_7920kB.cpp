#include<bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	set<long long int>pp;
	for(long long int i=2 ; i<=100005 ; i++)
	{
		for(long long int j=i*i ; j<=10000000005 ; j*=i)
		pp.insert(j);
	}
	vector<long long int>v(pp.begin(), pp.end());
//	cout<<v.size()<<" "<<pp.size()<<endl;
//	cout<<lower_bound(v.begin(), v.end(), 1000001)-v.begin()<<endl;
//	cout<<"v:";
//	for(int i=0 ; i<=20 ; i++)
//		cout<<v[i]<<" ";
//	cout<<endl;

	
	long long int dp[102235];
	dp[0]=1;

	for(int i=1 ; i<=1115 ; i++)
	for(int j=0 ; j<i ; j++)
		dp[i]=( dp[i] + (dp[j]*dp[i-j-1])%100000007 )%100000007;
//
//	for(int i=0 ; i<=1000 ; i++)
//		cout<<"i="<<i<<" dp[i]="<<dp[i]<<endl;

	dp[0]=0;

	int test;
	scanf("%d", &test);

	for(int t=1 ; t<=test ; t++)
	{
		long long int l, r;
		scanf("%lld %lld", &l, &r);

		int cnt=upper_bound(v.begin(), v.end(), r)-lower_bound(v.begin(), v.end(), l);
//		cout<<"l="<<l<<" r="<<r<<endl;
//		for(int k=0 ; v[k]<=r ; k++)
//			cout<<v[k]<<" ";
//		cout<<endl<<endl;;
//		cout<<"i="<<i<<" j="<<j<<endl;
//		for(int k=i ; k<=j ; k++)
//			cout<<v[k]<<" ";
//		cout<<endl;
//		cout<<"cnt="<<cnt<<endl;
		printf("Case %d: %lld\n", t, dp[cnt]);
	}
}
