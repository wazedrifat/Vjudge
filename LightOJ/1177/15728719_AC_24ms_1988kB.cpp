#include<bits/stdc++.h>
using namespace std;

const int MAX=10100;
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

int main()
{
	int test;
	cin>>test;

	for(int t=1 ; t<=test ; t++)
	{
		int n, m;
		cin>>n>>m;

		Dinic<int>d(200);

		d.addEdge(1, 2, INT_MAX);
		d.addEdge(2, 1, INT_MAX);
		d.addEdge(2*n-1, 2*n, INT_MAX);
		d.addEdge(2*n, 2*n-1, INT_MAX);

		for(int i=2 ; i<n ; i++)
		{
			int w;
			cin>>w;

			d.addEdge(2*i-1, 2*i, w);
			d.addEdge(2*i, 2*i-1, w);
		}

		while(m--)
		{
			int i, j, k;
			cin>>i>>j>>k;
			d.addEdge(2*i, 2*j-1, k);
			d.addEdge(2*j, 2*i-1, k);
		}

		cout<<"Case "<<t<<": "<<d.maxFlow(1, 2*n)<<endl;
	}
}
