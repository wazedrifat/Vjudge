#include<bits/stdc++.h>
using namespace std;

#define PII pair<int, int>

vector<int>g[205];
int visited[205];
int exist[205], degree[205];

void DFS(int v, int u=-1)
{
	visited[v]=1;

	for(auto w : g[v])
	if(!visited[w] && w)
		DFS(w, v);
}

bool HasUndirectedEulerPath(int n)//first is starting node & 2nd is ending node
{
	for(int i=0 ; i<n ; i++)
	if(degree[i]%2==1)
	{
//		cout<<"odd for i="<<i<<endl;
		return 0;
	}

	return 1;
}

int main()
{
	int n, r;

	while(scanf("%d %d", &n, &r)!=EOF)
	{
		for(int i=0 ; i<n ; i++)
		{
			g[i].clear();
			degree[i]=visited[i]=0;
		}

		for(int i=0 ; i<r ; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);

			g[u].push_back(v);
			g[v].push_back(u);

			degree[u]++;
			degree[v]++;
			exist[u]=exist[v]=1;
		}

		int f=0;

		if(!HasUndirectedEulerPath(n) || r<2)
		{
//			cout<<"no\n";
			printf("Not Possible\n");
			continue;
		}

		DFS(0);
		for(int i=0 ; i<n ; i++)
		if(!visited[i] && exist[i])
		{
			printf("Not Possible\n");
			f=1;
			break;
		}

		if(!f)
			printf("Possible\n");
	}
}
