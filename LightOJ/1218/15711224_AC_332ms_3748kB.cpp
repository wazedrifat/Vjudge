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

vector<int>a;
map<int, int>repeat;
int vist[500], mult[500];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

	int test;
	cin>>test;

	for(int t=1 ; t<=test ; t++)
	{
		int n, cnt=0;
		cin>>n;

        memset(vist, 0, sizeof vist);
        a.clear();
        repeat.clear();

		for(int i=0 ; i<n ; i++)
        {
            int v;
            cin>>v;

            if(repeat.find(v)==repeat.end())
            {
                repeat[v]=1;
                a.push_back(v);
            }
        }

        sort(a.begin(), a.end());
        n=a.size();

//        cout<<"array ("<<n<<") : ";
//        for(auto v : a)
//            cout<<v<<" ";
//        cout<<endl;

        init (500, 500);

		for(int i=0 ; i<n ; i++)
		for(int j=i+1 ; j<n ; j++)
			if(a[j]%a[i]==0)
			addEdge(i, j);

		int cur=1, num=n-maxMatching(), now=0, m=n;

        cout<<"Case "<<t<<":";
//        cout<<"num="<<num<<endl;
        while(cur<=num )
        {
//            cout<<"cur="<<cur<<" num="<<num<<endl;
            m--;
            init(500, 500);
            int mult=0;

            for(int i=now+1 ; i<n ; i++)
                mult+=(a[i]%a[now]==0 || vist[i]);

            for(int i=now+1 ; i<n ; i++)
            for(int j=i+1 ; j<n ; j++)
                if(a[j]%a[now] && a[i]%a[now] && a[j]%a[i]==0 && !vist[i] && !vist[j])
                {
                    addEdge(i, j);
//                    if(now==14)
//                        cout<<"("<<a[i]<<","<<a[j]<<") ";
                }
//            if(now==14)
//                cout<<endl;

//            cout<<"a["<<now<<"]="<<a[now]<<" n="<<m<<" mult="<<mult<<" res="<<maxMatching()<<" cur="<<cur<<endl;
//            cout<<"if : "<<m-mult-maxMatching()+cur<<"=="<<num<<" : "<<(n-maxMatching()+cur==num)<<endl;
            if(m-mult-maxMatching()+cur==num && !vist[now])
            {
//                cout<<endl<<"ans=";
                cout<<" "<<a[now];
//                cout<<endl<<endl;
                cur++;
                for(int i=now+1 ; i<n ; i++)
                vist[i]|=(a[i]%a[now]==0);
            }
            now++;
        }
        cout<<endl;//<<endl;
	}
}
