#include<bits/stdc++.h>
using namespace std;

long long dp[50][2][50];
int dig[50];

long long digit(int pos, int prev=0, int res=0, bool flag=1)
{
	if(pos==-1)						return res;
	if(!flag&&dp[pos][prev][res]!=-1)	return dp[pos][prev][res];

	int hi=flag?dig[pos]:1;
	long long cnt=0;

	for(int i=0;i<=hi;i++)
		cnt+=digit(pos-1, i ,res+(prev&i), flag&(i==hi));

	if(!flag)	dp[pos][prev][res]=cnt;

	return cnt;
}

int main()
{
	//freopen("input.txt", "r", stdin);
    int test,i;
    long long n;
    cin>>test;
    for(int t=1 ; t<=test ; t++)
    {
		memset(dp,-1,sizeof(dp));
		cin>>n;

		int len=0;
		while(n)
		{
			dig[len++]=n%2;
			n=n/2;
		}

		cout<<"Case "<<t<<":"<<" "<<digit(len-1)<<endl;
    }
}
