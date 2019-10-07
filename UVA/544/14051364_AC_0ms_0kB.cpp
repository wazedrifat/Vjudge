#include<bits/stdc++.h>
using namespace std;

#define MX 300

struct edge
{
	int u, v, w;
	edge(int _u, int _v, int _w)
	{
	    u=_u;   v=_v;   w=_w;
	}
};
vector<int>g[MX], cost[MX];
int visited[MX];
vector<edge>e;
int	pr[MX];

bool comp(edge a, edge b){	return a.w>=b.w;	}

int Find(int n)
{
    int m=n;
    while(pr[m]!=m)
    m=pr[m];

    while(pr[n]!=n)
    {
        int k=pr[n];
        pr[n]=m;
        n=k;
    }
    return m;
}

void mst(int node)
{
    for(int i=0 ; i<node ; i++)
    {
        g[i].clear();
        cost[i].clear();
    }

	sort(e.begin(),e.end(),comp);
	for(int i=0 ; i<=node ; i++)	pr[i]=i;

	int cnt=0,sum=0;
	for(int i=0 ; i<e.size() ; i++)
	{
		int u=Find(e[i].u);
		int v=Find(e[i].v);

		if(u!=v)
		{
			pr[u]=v;
			cnt++;

			g[ e[i].u ].push_back( e[i].v );
			g[ e[i].v ].push_back( e[i].u );
			cost[ e[i].u ].push_back( e[i].w );
			cost[ e[i].v ].push_back( e[i].w );

			if(cnt==node-1)	break;
		}
	}
}

int dfs(int v, int w)
{
    visited[v]=1;

	//cout<<"v="<<v<<endl;
    if(v==w)    return INT_MAX-1;

    for(int i=0 ; i<g[v].size() ; i++)
    if(!visited[ g[v][i] ])
    {
        int d=dfs(g[v][i], w);

        //cout<<"d="<<d<<" v="<<v<<" g[v][i]="<<g[v][i]<<" cost="<<cost[v][i]<<endl;
        if(d!=INT_MAX)  return min(d, cost[v][i] );
    }

    return INT_MAX;
}

int main()
{
    int n, m, test=1;
    map<string, int>str;

    while(scanf("%d %d", &n, &m) && (n||m) )
    {
        e.clear();
        str.clear();
        int id=0;
        for(int i=0 ; i<m ; i++)
        {
            char c1[35], c2[35];
            int u=id, v=id, w;
            scanf("%s %s %d", c1, c2, &w);

            if(str.find(c1)==str.end())     str[c1]=u=id++;
            else                            u=str[c1];

            if(str.find(c2)==str.end())     str[c2]=v=id++;
            else                            v=str[c2];

            e.push_back(edge(u, v, w));
        }

        mst(n);

        char c1[35], c2[35];
            scanf("%s %s", c1, c2);

        for(int i=0 ; i<n ; i++)
            visited[i]=0;

        cout<<"Scenario #"<<test++<<endl;
        cout<<dfs(str[c1], str[c2])<<" tons"<<endl<<endl;
    }
}
