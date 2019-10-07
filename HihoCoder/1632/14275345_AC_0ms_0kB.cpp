#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, f[105][105];
    const int x[4]={0, 1, 0, -1};
    const int y[4]={1, 0, -1, 0};
	string s[105], res;

    while(scanf("%d", &n)!=EOF)
	{
		res.clear();
		for(int i=0 ; i<n ; i++)
		{
			s[i].clear();
			for(int j=0 ; j<n ; j++)
				f[i][j]=0;
		}

		for(int i=0 ; i<n ; i++)
			cin>>s[i];

		bool c=1;
		for(int i=0 ; i<n ; i++, c=1-c)
		{
			string temp="";
			for(int j=0 ; j<=i ; j++)
				temp+=s[j][i-j];

			if(c)
				reverse(temp.begin(), temp.end());
			res+=temp;
		}

		for(int i=1 ; i<n ; i++, c=1-c)
		{
			string temp="";
			for(int j=i, k=n-1 ; k>=i ; j++, k--)
				temp+=s[j][k];

			if(c)
				reverse(temp.begin(), temp.end());
			res+=temp;
		}

		char str[105][105];

		for(int i=0, j=0, d=0, k=0 ; !f[i][j] ; k++, i+=x[d], j+=y[d])
		{
			str[i][j]=res[k];
			f[i][j]=1;

			int a=i+x[d], b=j+y[d];
			if(a<0 || a>=n || b<0 || b>=n || f[a][b])	d=(d+1)%4;
		}

		for(int i=0 ; i<n ; i++)
		{
			for(int j=0 ; j<n ; j++)
				cout<<str[i][j];
			cout<<endl;
		}
	}
}
