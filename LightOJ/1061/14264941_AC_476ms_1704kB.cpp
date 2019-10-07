#include<bits/stdc++.h>
using namespace std;

int ChessNo=0, fc[10], fd1[10], fd2[20], temp[10], dp[10][(1<<8)], x[10], y[10], chess[100][10];

void ChessBoard(int r=0)
{
	if(r>=8)
	{
		for(int i=0 ; i<8 ; i++)
			chess[ChessNo][i]=temp[i];
		ChessNo++;
		return;
	}

	for(int i=0 ; i<8 ; i++)
	{
		if(!fc[i] && !fd1[r+i] && !fd2[8+r-i])
		{
			fc[i]=1;	fd1[r+i]=1;		fd2[8+r-i]=1;
			temp[r]=i;
			ChessBoard(r+1);
			fc[i]=0;	fd1[r+i]=0;		fd2[8+r-i]=0;
		}
	}
}

int dis(int sr, int sc, int er, int ec)
{
	if(sr==er && sc==ec)	return 0;
	if(sr==er || sc==ec || sr-sc==er-ec || sr+sc==er+ec)	return 1;
	return 2;
}

int rec(int conf, int n=0, int mask=0)
{
	if(n>=8)	return 0;
	int &d=dp[n][mask];
	if(d!=-1)	return d;

	d=INT_MAX;
	for(int i=0 ; i<8 ; i++)
		if( !(mask&(1<<i)) )
		{
			d=min(d, dis(x[n], y[n], i, chess[conf][i]) + rec(conf, n+1, (mask|(1<<i)) ) );
//			cout<<"n="<<n<<" i="<<bitset<8>(i)<<" dis("<<x[n]<<", "<<y[n]<<", "<<i<<", "<<chess[conf][i]<<")="<<dis(x[n], y[n], i, chess[conf][i])<<" + "<<rec(conf, n+1, (mask|(1<<i)) )<<endl;
		}
//	cout<<"n= "<<n<<" mask="<<bitset<8>(mask)<<"dp="<<d<<endl;
	return d;
}

int main()
{
//	freopen("F.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int test;
	cin>>test;

	ChessBoard();

//	for(int i=0 ; i<8 ; i++, cout<<endl)
//	for(int j=0 ; j<8 ; j++)
//		if(chess[57][i]==j)
//		cout<<'q';
//		else cout<<'.';

	for(int t=1 ; t<=test ; t++)
	{
		for(int i=0,k=0 ; i<8 ; i++)
		{
			string s;
			cin>>s;

			for(int j=0 ; j<s.length() ; j++)
				if(s[j]=='q')
				{
					x[k]=i;	y[k]=j;	k++;
				}
		}

		int res=INT_MAX;
		for(int i=0 ; i<ChessNo ; i++)
		{
			memset(dp, -1, sizeof dp);
			res=min(res, rec(i) );
//			cout<<"ChessN0="<<i<<" rec="<<rec(i)<<endl;
		}
//		memset(dp, -1, sizeof dp);
//		int res=rec(57);
		printf("Case %d: %d\n", t, res);
	}
}
