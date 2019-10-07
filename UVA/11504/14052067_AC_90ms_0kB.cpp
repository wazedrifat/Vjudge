#include<bits/stdc++.h>
using namespace std;

#define MX 100005

vector<int>g[MX];
int visited[MX];
struct type
{
	int in, out, n;
	type(int _n=0, int _in=0, int _out=0)
	{
		n=_n;	in=_in;	out=_out;
	}
}node[MX];

bool cmp(type a, type b)
{
	return a.in==b.in?	a.out>=b.out : a.in<b.in;
}

void dfs(int n)
{
	visited[n]=1;

	for(auto w : g[n])
	if(!visited[w])
	dfs(w);
}

int main()
{
	int t;

	scanf("%d", &t);

	while(t--)
	{
		int n, m;
		scanf("%d %d", &n, &m);

		for(int i=1 ; i<=n ; i++)
		node[i]=type(i, 0, 0);

		for(int i=0 ; i<m ; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);

			g[u].push_back(v);
			node[v].in++;
			node[u].out++;
		}
		stable_sort(node+1, node+n+1, cmp);

		for(int i=1 ; i<=n ; i++)
		visited[i]=0;

		int cnt=0;
		for(int i=1 ; i<=n ; i++)
		if(!visited[ node[i].n ])
		{
			cnt++;
			dfs( node[i].n );
		}

		cout<<cnt<<endl;

		for(int i=0 ; i<=n ; i++)
			g[i].clear();
	}
}
