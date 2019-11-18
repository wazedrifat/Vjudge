#include<bits/stdc++.h>
using namespace std;

#define MX 300005
#define MOD 998244353
#define ll long long int

ll two[MX], c1[MX], c2[MX];
int cnt;
vector<int>g[MX];
bool flag[MX], vis[MX];

int dfs(int u)
{
	vis[u]=1;

	int sum=(flag[u]==1);
	for(auto v : g[u])
		if(vis[v] && flag[v]==flag[u])
			return -1;
		else if(!vis[v])
		{
			flag[v]=1-flag[u];
			int c=dfs(v);

			if(c>=0)	sum+=c;
			else return -1;
		}
	return sum;
}

int main()
{
	int t;
	cin>>t;

	two[0]=(ll)1;
	for(int i=1 ; i<MX ; i++)
		two[i]=(two[i-1]*(ll)2)%MOD;

	while(t--)
	{
		int n, m;
		cin>>n>>m;

		for(int i=1 ; i<=n ; i++)
			g[i].clear();

		for(int i=0 ; i<m ; i++)
		{
			int u, v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}


		for(int i=0 ; i<=n ; i++)
		{
			vis[i]=0;
			flag[i]=0;
		}

		cnt=0;
		for(int i=1 ; i<=n ; i++)
			if(!vis[i])
			{
				flag[i]=0;
				c1[cnt++]=dfs(i);
			}

		cnt=0;
		for(int i=0 ; i<=n ; i++)
		{
			vis[i]=0;
			flag[i]=0;
		}

		for(int i=1 ; i<=n ; i++)
			if(!vis[i])
			{
				flag[i]=1;
				c2[cnt++]=dfs(i);
			}


		ll res=1;
		for(int i=0 ; i<cnt; i++)
			res=( res * ( (c1[i]>=0)*two[ c1[i] ]+(c2[i]>=0)*two[c2[i] ] )%MOD )%MOD;
		cout<<res<<endl;
	}
}