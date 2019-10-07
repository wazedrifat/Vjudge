#include<bits/stdc++.h>
using namespace std;

#define MX 1003

int vis[MX], dis[MX];
vector<int>g[MX];

void BFS(int source)
{
    queue<int>Q;

    Q.push(source);
    dis[source]=0;
    vis[source]=1;

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();

        for(auto v : g[u])
            if(!vis[v])
            {
                dis[v]=dis[u]+6;
                vis[v]=1;
                Q.push(v);
            }
    }
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, m;
        cin>>n>>m;

        for(int i=1 ; i<=n ; i++)
        {
            g[i].clear();
            vis[i]=0;
            dis[i]=-1;
        }

        while(m--)
        {
            int u,v ;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int s;
        cin>>s;

        BFS(s);

        for(int i=1 ; i<=n ; i++)
            if(i!=s)
                cout<<dis[i]<<" ";
        cout<<endl;
    }
}
