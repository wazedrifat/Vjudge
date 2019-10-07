#include<bits/stdc++.h>
using namespace std;

#define MX 26

vector<int>g[MX], cost[MX], v;
int dist[MX], degree[MX], parent[MX];
int Dijkstra(int source, int destination)
{
    map<int, int>m;

    for(int i=0 ; i<MX ; i++)
    {
    	dist[i]=INT_MAX;
    	parent[i]=-1;
	}

	m[0]=source;
	dist[source]=0;

    while(!m.empty())
    {
        map<int, int>::iterator it=m.begin();

        int u=it->second;
        m.erase(it);

        for(int i=0 ; i<g[u].size() ; i++)
        {
            int v=g[u][i];
            int NewCost=dist[u]+cost[u][i];

            if(NewCost<dist[v])
            {
            	parent[v]=u;
                dist[v]=NewCost;
                m[ NewCost ]=v;
            }
        }
    }

    return dist[destination];
}

int main()
{
	//freopen("input.txt", "r", stdin);
	char ch[10000];
	while(scanf("%s", ch)!=EOF)
	{
		string s=ch;
		int sum=0;

		for(int i=0 ; i<26 ; i++)
		{
			g[i].clear();
			cost[i].clear();
			degree[i]=0;
		}

		while(s!="deadend")
		{
			int x=s.front()-'a', y=s.back()-'a';

			g[x].push_back(y);
			g[y].push_back(x);

			int c=s.length();
			sum+=c;
			cost[x].push_back(c);
			cost[y].push_back(c);

			degree[x]++;
			degree[y]++;
			cin>>s;
		}

//		for(int i=0 ; i<MX ; i++)
//		{
//			cout<<"i="<<(char)(i+'a')<<" : ";
//			for(int j=0 ; j<g[i].size() ; j++)
//				cout<<(char)(g[i][j]+'a')<<"("<<cost[i][j]<<") ";
//			cout<<endl;
//		}
		for(int i=0 ; i<26 ; i++)
		if(degree[i]%2)
			v.push_back(i);

		if(v.size())
		sum+=Dijkstra(v[0], v[1]);

		cout<<sum<<endl;
		v.clear();
	}
}
