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
//   	cout<<"Edge : u="<<u<<" v="<<v<<" cap="<<cap<<endl;
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
//	freopen("input.txt", "r", stdin);
	int test;
	scanf("%d", &test);

	for(int t=1 ; t<=test ; t++)
	{
		char c[200], c1;
		int n, d, a[200];
		scanf("%d%d", &n, &d);

		for(int i=1 ; i<=n ; i++)
		{
			scanf(" %c-%d", &c[i], &a[i]);
//			cout<<"c="<<c[i]<<" a[i]="<<a[i]<<endl;
		}

		int l=0, h=d, mid, res=0;
		while(l<=h)
		{
			mid=(l+h)/2;

			Dinic<int>dn(1000);
			int src=0, snk=2*n+5;

			for(int i=1 ; i<=n ; i++)
			{
				int cap=2;
				if(c[i]=='S')	cap=1;

//				cout<<"i="<<i<<" d="<<d<<" a[i]="<<a[i]<<" mid="<<mid<<endl;
				dn.addEdge(2*i-1, 2*i, cap);
				if(a[i]<=mid)
				{
//					cout<<"from source : ";
					dn.addEdge(src, 2*i-1, 2);
				}
				if(d-a[i]<=mid)
				{
//					cout<<"to sink : ";
					dn.addEdge(2*i, snk, 2);
				}
			}

			if(mid>=d)	dn.addEdge(src, snk, 2);

			for(int i=1 ; i<=n ; i++)
			for(int j=i+1 ; j<=n ; j++)
				if(a[j]-a[i]<=mid)
				{
					dn.addEdge(2*i, 2*j-1, 2);
					dn.addEdge(2*j, 2*i-1, 2);
				}
//			cout<<"l="<<l<<" h="<<h<<" mid="<<mid<<" res="<<res<<endl;

			if(dn.maxFlow(src, snk)>=2)
			{
				h=mid-1;
				res=mid;
			}
			else		l=mid+1;
		}
		printf("Case %d: %d\n", t, res);
//		cout<<"Case "<<t<<": "<<m<<endl;

	}

}
