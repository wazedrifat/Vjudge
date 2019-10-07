#include<bits/stdc++.h>
using namespace std;

#define BLM 3
#define MX (1<<30)

int dp[10][(1<<8)][(1<<8)], row[10], r, c;

int rec(int pos, int prev, int cur)
{
//	cout<<"head  pos="<<pos<<" cur="<<bitset<BLM>(cur)<<" prev="<<bitset<BLM>(prev)<<endl;
	if(pos>=r)
	{
//		cout<<"return "<<__builtin_popcount(prev)<<endl;
		if(__builtin_popcount(prev)==c)	return 0;
		else							return MX;

	}
//	if(dp[pos][cur][prev]!=MX)			return dp[pos][cur][prev];

	int res=MX;

	for(int i=0 ; i<(1<<c) ; i++)
	{
		int cnt=0, nxt=row[pos+1], pr=prev, cr=cur;
		for(int j=0 ; j<c ; j++)
			if( (i&(1<<j)) )
			{
				cnt++;
				pr^=(1<<j);		cr^=(1<<j);		nxt^=(1<<j);
				if(j+1<c)
				{
					pr^=(1<<(j+1));	cr^=(1<<(j+1));	nxt^=(1<<(j+1));
				}
				if(j-1>=0)
				{
					pr^=(1<<(j-1));	cr^=(1<<(j-1));	nxt^=(1<<(j-1));
				}
			}
//		cout<<"pr="<<bitset<BLM>(prev)<<" cr="<<bitset<BLM>(cur)<<" nxt="<<bitset<BLM>(row[pos+1])<<" i="<<bitset<BLM>(i)<<endl;
//		cout<<"pr="<<bitset<BLM>(pr)<<" cr="<<bitset<BLM>(cr)<<" nxt="<<bitset<BLM>(nxt)<<" count="<<__builtin_popcount(pr)<<endl<<endl;
		if(!pos || __builtin_popcount(pr)==c)
		{
			res=min( res, cnt+rec( pos+1, cr, nxt));
//			cout<<"if" <<"head  pos="<<pos<<" cur="<<bitset<BLM>(cur)<<" prev="<<bitset<BLM>(prev)<< "res="<<res<<" cnt="<<cnt<<" rec="<<rec( pos+1, cr, nxt)<<endl;
		}
	}
//	cout<<"pos="<<pos<<" cur="<<bitset<BLM>(cur)<<" prev="<<bitset<BLM>(prev)<<" dp="<<res<<endl;
	return dp[pos][cur][prev]=res;
}

int main()
{
//	freopen("j.txt", "r", stdin);

	int test;
	cin>>test;

	for(int t=1 ; t<=test ; t++)
	{
		cin>>r>>c;

		memset(row, 0, sizeof row);
		for(int i=0 ; i<8 ; i++)
		for(int j=0 ; j<(1<<8) ; j++)
		for(int k=0 ; k<(1<<8) ; k++)
			dp[i][j][k]=MX;

		for(int i=0 ; i<r ; i++)
		{
			string s;
			cin>>s;

			for(int j=0 ; j<s.length() ; j++)
				if(s[j]== '*' )
				row[i]|=(1<<j);
		}

		int res=rec(0, 0, row[0]);

		if(res==MX)	cout<<"Case "<<t<<": "<<"impossible"<<endl;
		else		cout<<"Case "<<t<<": "<<res<<endl;
	}
}
