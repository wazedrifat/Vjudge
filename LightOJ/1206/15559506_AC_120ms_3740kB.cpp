#include<bits/stdc++.h>
using namespace std;

#define MX 500
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

class PT
{
public:
	int x, y;
	PT(int _x=0, int _y=0)
	{
		x=_x;	y=_y;
	}
};

ostream& operator<<(ostream& os, PT& p)
{
	os<<"("<<p.x<<", "<<p.y<<")";
}

int dis(PT p, PT q)
{
	return abs(p.x-q.x)+abs(p.y-q.y);
}

int main()
{
	int test;
	cin>>test;

	for(int t=1 ; t<=test ; t++)
	{
		init(4000, 4000);
		int tm[MX];
		PT s[MX], f[MX];
		char ch;
		int n;
		cin>>n;

		for(int i=0 ; i<n ; i++)
		{
			int h, m;
			cin>>h>>ch>>m>>s[i].x>>s[i].y>>f[i].x>>f[i].y;
			tm[i]=h*60+m;
		}

		for(int i=0 ; i<n ; i++)
		{
			int NextTime=tm[i]+dis(s[i], f[i]);

//			cout<<"i="<<i<<" NextTime="<<NextTime<<"="<<tm[i]<<"+"<<dis(s[i], f[i])<<endl;

			for(int j=0 ; j<n ; j++)
				if(NextTime+dis(f[i], s[j])<tm[j])	addEdge(i, j);
//				{
//					Time tt=NextTime+dis(f[i], s[j]);
//
////					cout<<"if : "<<tt<<"="<<NextTime<<"+"<<dis(f[i], s[j])<<" < "<<tm[j]<<endl;
////					cout<<"edge : "<<i<<" "<<j<<endl;
//				}
		}

		cout<<"Case "<<t<<": "<<n-maxMatching()<<endl;
	}
}
