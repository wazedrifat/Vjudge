#include<bits/stdc++.h>
using namespace std;

#define PII pair<int, int>

// up, right, down ,left
int dirX[]={ 0, 1, 0, -1};
int dirY[]={-1, 0, 1,  0};

const int MAX=20025;
int que[MAX];
template <class T>
struct Edge {
   int to, next;
   T cap, flow;
   Edge(int to, int next, T cap) {
      this->to = to;
      this->next = next;
      this->cap = cap;
      this->flow = 0;
   }
};
template <class T>
struct Dinic {
   T INF;
   const int nodes;
   int source, sink, lvl[MAX], nodeEnd[MAX], last[MAX];
   vector < Edge <T> > edgeList;

   Dinic(int n) : nodes(n), INF(numeric_limits<T>::max() / 4) { fill(nodeEnd, nodeEnd+n, -1); }
   void addEdge(int u, int v, T cap = 1) {
      edgeList.push_back(Edge<T> (v, nodeEnd[u], cap));
      nodeEnd[u] = (int)edgeList.size()-1;
      edgeList.push_back(Edge<T> (u, nodeEnd[v], 0));
      nodeEnd[v] = (int)edgeList.size()-1;
   }

   // bfs
   bool createLevel() {
      memset(lvl, -1, nodes * sizeof(int));
      int qs = 0, qt = 0;
      que[qs] = source, lvl[source] = 0;

      while(qs <= qt) {
         int nd = que[qs++], ch;
         for(int i = nodeEnd[nd]; i != -1; i = edgeList[i].next)
            if(lvl[ch = edgeList[i].to] == -1 && edgeList[i].cap > edgeList[i].flow)
               lvl[ch] = lvl[nd] + 1, que[++qt] = ch;
      }

      return lvl[sink] != -1;
   }

   // dfs
   T blockingFlow(int nd, T flow) {
      if(nd == sink) return flow;
      int ch;
      T pflow = flow;

      for(int &i = last[nd]; i != -1; i = edgeList[i].next) if(lvl[ch = edgeList[i].to] == lvl[nd]+1) {
         T pushed = blockingFlow(ch, min(pflow, edgeList[i].cap - edgeList[i].flow));
         pflow -= pushed;
         edgeList[i].flow += pushed;
         edgeList[i ^ 1].flow -= pushed;
         if(!pflow) break;
      }

      return flow - pflow;
   }

   T maxFlow(int src, int snk) {
      //REP(i, edgeList.size()) edgeList[i].flow = 0;
      source = src, sink = snk;
      T tot = 0;

      while(createLevel()) {
         memcpy(last, nodeEnd, nodes * sizeof(int));
         tot += blockingFlow(source, INF);
      }

      return tot;
   }
};

PII id(int i, int j, int m)
{
	int x=i*m+j+1;
	return PII(2*x-1, 2*x);
}

int main()
{
//	freopen("input.txt", "r", stdin);
	int test;
	cin>>test;

	for(int t=1 ; t<=test ; t++)
	{
		Dinic<int>d(20020);
		char ch[200][200];
		int n, m, cnt=0;
		cin>>n>>m;

		for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<m ; j++)
			cin>>ch[i][j];

		int source=0, sink=20005;
		for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<m ; j++)
		{
			PII x=id(i, j, m);

			d.addEdge(x.first, x.second, 1);

			if(!i || !j || i==n-1 || j==m-1)	d.addEdge(x.second, sink, 1);
			if(ch[i][j]=='*')					d.addEdge(source, x.first, 1);

			cnt+=(ch[i][j]=='*');
			for(int k=0 ; k<4 ; k++)
			{
				int NR=i+dirY[k], NC=j+dirX[k];
				if(NR<0 || NR>=n || NC<0 || NC>=m || ch[NR][NC]=='*')	continue;

				PII y=id(NR, NC, m);
				d.addEdge(x.second, y.first, 1);
//					d.addEdge(y.second, x.first);
			}
		}
		if(cnt==d.maxFlow(source, sink))	cout<<"Case "<<t<<": yes"<<endl;
		else								cout<<"Case "<<t<<": no"<<endl;
	}
}
