#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int main()
{
  int n, m, t=1;
  int parent[6000];
  int Rank[6000];
    map<string, int>str;

  while(scanf("%d %d", &n, &m) && (n || m) )
  {
      int id=0;
      str.clear();

    for(int i=0 ; i<n ; i++)
    {
        char ch[35];
        scanf("%s", ch);

        str[ch]=id++;

        parent[i]=i;
        Rank[i]=1;
    }

    for(int i=0 ; i<m ; i++)
    {
        char c1[35], c2[35];
        scanf("%s%s", c1, c2);

        int u=str[c1], v=str[c2];

        while(parent[u]!=u)
        u=parent[u];

         while(parent[v]!=v)
         v=parent[v];

         if(u!=v)
            Rank[u]+=Rank[v];
        parent[v]=u;
    }

    int cnt=INT_MIN;
    for(int i=0 ; i<n ; i++)
    cnt=max(cnt, Rank[i]);

    cout<<cnt<<endl;
  }
  return 0;
}
