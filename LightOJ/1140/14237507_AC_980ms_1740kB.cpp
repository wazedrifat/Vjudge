#include<bits/stdc++.h>
using namespace std;

int A[40], B[40];
long long int dp[40][2][2][40];

long long int digitdp(int pos, int high=1, int low=1, int sum=0, int st=1, string s="")
{
	if(pos<0)
	{
//		cout<<"completed pos="<<pos<<" high="<<high<<" low="<<low<<" sum="<<sum<<" s="<<s<<endl;
		return sum+st;
	}
	if(dp[pos][high][low][sum]!=-1)
	{
		//cout<<"repeat pos="<<pos<<" high="<<high<<" low="<<low<<" sum="<<sum<<" dp="<<dp[pos][high][low][sum]<<endl;
		return dp[pos][high][low][sum];
	}

	int hi= high?	B[pos] : 9;
	int lo=low?		A[pos] : 0;

	long long int cnt=0;
//	cout<<"pos="<<pos<<" high="<<high<<" low="<<low<<endl;
	for(int i=lo ; i<=hi ; i++)
		cnt+=digitdp(pos-1, high&(i==hi), low&(i==lo), sum+(i==0 && !st), st&!i, s+(char)(i+'0'));

//	cout<<"pos="<<pos<<" high="<<high<<" low="<<low<<" sum="<<sum<<" dp="<<cnt<<endl;
	return dp[pos][high][low][sum]=cnt;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	int test;
	cin>>test;

	for(int t=1 ; t<=test ; t++)
	{
		memset(dp, -1, sizeof dp);
		memset(A, 0, sizeof A);
		memset(B, 0, sizeof B);

		long long int n, m;
		cin>>n>>m;

		int i=0;
		long long  int x=n;
		while(x)
		{
			A[i++]=x%10;
			x/=10;
		}
		i=0;	x=m;
		while(x)
		{
			B[i++]=x%10;
			x/=10;
		}
//		cout<<"tot="<<i<<endl;
		cout<<"Case "<<t<<": "<<digitdp(i-1)<<endl;
	}
}
