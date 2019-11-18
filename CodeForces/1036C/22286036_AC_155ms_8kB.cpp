#include<bits/stdc++.h>
using namespace std;

int a[20], b[20];
long long int dp[20][5][3], len;

long long int rec(int arr[], int pos, int n=0, int hf=1)
{
//	cout<<"pos="<<pos<<" n="<<n<<endl;
	if(n==3 || pos<0)	return 1;

	long long int &d=dp[pos][n][hf];
	if(d!=-1)	return d;

	int h=hf?	arr[pos] : 9;

//	cout<<"loop : ";
	long long int cnt=0;
	for(int i=0 ; i<=h ; i++)
	{
//		cout<<"	pos="<<pos<<" i="<<i<<" rec="<<
//		int tmp=rec(arr, pos-1, n+(i!=0));
//		cout<<tmp<<
		cnt+=rec(arr, pos-1, n+(i!=0), hf&(i==h));
	}

//	cout<<"pos="<<pos<<" n="<<n<<" d="<<cnt<<endl;
	return d=cnt;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
	{
		long long int l, r;
		cin>>l>>r;

		memset(dp, -1, sizeof dp);
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);

		int i=0, f=0;
		while(l)
		{
			f+=(l%10!=0);
			a[i++]=l%10;
			l/=10;

		}
		long long int res1=rec(a, i-1);

		int j=0;
		while(r)
		{
			b[j++]=r%10;
			r/=10;
		}

//		cout<<endl<<endl;
		memset(dp, -1, sizeof dp);
		long long int res2=rec(b, j-1);
		long long int res=res2-res1+(f<=3);
		cout<<res<<endl;
	}
}