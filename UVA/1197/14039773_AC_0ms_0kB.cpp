#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int main()
{
  int n, m, t=1;
  int parent[40000];
  int Rank[40000];

  while(scanf("%d %d", &n, &m) && (n || m) )
  {
    for(int i=0 ; i<n ; i++)
    {
        parent[i]=i;
        Rank[i]=1;
    }

    for(int i=0 ; i<m ; i++)
    {
        int k, u;
        scanf("%d", &k);

        if(k)
        {
            k--;
            cin>>u;

            while(parent[u]!=u)
            u=parent[u];
        }

        while(k--)
        {
            int v;
            cin>>v;

             while(parent[v]!=v)
             v=parent[v];

             if(u!=v)
                Rank[u]+=Rank[v];
            parent[v]=u;
        }
    }

    int u=0;
    while(parent[u]!=u)
        u=parent[u];

    cout<<Rank[u]<<endl;
  }
  return 0;
}
