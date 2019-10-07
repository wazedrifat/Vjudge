#include<bits/stdc++.h>
using namespace std;
 
const int MAXN1 = 50000;
const int MAXN2 = 50000;
const int MAXM = 150000;
 
int n1, n2, edges, last[MAXN1], prv[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];
 
void init(int _n1, int _n2) {
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(last, last + n1, -1);
}
 
void addEdge(int u, int v) {
    head[edges] = v;
    prv[edges] = last[u];
    last[u] = edges++;
}
 
void bfs() {
    fill(dist, dist + n1, -1);
    int sizeQ = 0;
    for (int u = 0; u < n1; ++u) {
        if (!used[u]) {
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for (int i = 0; i < sizeQ; i++) {
        int u1 = Q[i];
        for (int e = last[u1]; e >= 0; e = prv[e]) {
            int u2 = matching[head[e]];
            if (u2 >= 0 && dist[u2] < 0) {
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}
 
bool dfs(int u1) {
    vis[u1] = true;
    for (int e = last[u1]; e >= 0; e = prv[e]) {
        int v = head[e];
        int u2 = matching[v];
        if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)) {
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}
 
int maxMatching() {
    fill(used, used + n1, false);
    fill(matching, matching + n2, -1);
    for (int res = 0;;) {
        bfs();
        fill(vis, vis + n1, false);
        int f = 0;
        for (int u = 0; u < n1; ++u)
            if (!used[u] && dfs(u))
                ++f;
        if (!f)
            return res;
        res += f;
    }
}
 
#define MX 200
 
vector<int>g[2][MX], level[2][MX];
int parent[2][MX], children[2][MX], vist[2][MX];
 
class edge
{
public:
    int a, b;
    edge(int _a=0, int _b=0)
    {
        a=_a;   b=_b;
    }
};
vector<edge>e[MX][MX];
 
bool solve(int n, int m, int root=1)
{
//    cout<<"n="<<n<<" m="<<m<<endl;
    vist[0][n]=vist[1][m]=1;
 
    e[n][m].clear();
    for(int i=0 ; i<g[0][n].size() ; i++)
        if(!vist[0][ g[0][n][i] ])
        for(int j=0 ; j<g[1][m].size() ; j++)
            if(!vist[1][ g[1][m][j] ] && solve(g[0][n][i], g[1][m][j], root))
            {
                e[n][m].push_back( edge(i, j) );
//                cout<<"n="<<n<<" m="<<m<<" i="<<i<<" j="<<j<<endl;
            }
 
    init(MX, MX);
    for(int i=0 ; i<e[n][m].size() ; i++)
    {
        edge &ed=e[n][m][i];
        addEdge(ed.a, ed.b);
    }
    vist[0][n]=vist[1][m]=0;
//    cout<<"n="<<n<<" m="<<m<<" match="<<maxMatching()<<" child="<<g[1][m].size()<<" return="<<(maxMatching()==g[1][m].size()-(int)(n!=root))<<endl;
    return (maxMatching()==g[1][m].size()-(int)(n!=root));
}
 
int main()
{
//    freopen("input.txt", "r", stdin);
    int test;
    cin>>test;
 
    for(int t=1 ; t<=test ; t++)
    {
 
        for(int i=0 ; i<MX ; i++)
        {
            g[0][i].clear();
            g[1][i].clear();
        }
 
        int n;
        cin>>n;
 
        for(int i=0 ; i<n-1 ; i++)
        {
            int u, v;
            cin>>u>>v;
            g[0][u].push_back(v);
            g[0][v].push_back(u);
        }
 
        int m;
        cin>>m;
 
        for(int i=0 ; i<m-1 ; i++)
        {
            int u, v;
            cin>>u>>v;
            g[1][u].push_back(v);
            g[1][v].push_back(u);
        }
 
        bool f=0;
        for(int i=1 ; i<=1 ; i++)
        {
            for(int i=0 ; i<=MX ; i++)  vist[0][i]=vist[1][i]=0;
            f|=solve(i, i, i);
        }
 
        cout<<"Case "<<t<<": ";
        if(f)   cout<<"Yes\n";
        else    cout<<"No\n";
    }
}
 