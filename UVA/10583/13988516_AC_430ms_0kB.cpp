#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, parent[100000], t=1;
  set<int>s;
  while(cin>>n>>m && (n || m) )
  {
  	for(int i=0 ; i<=n ; i++)
  	parent[i]=i;
  	
  	for(int i=0 ; i<m ; i++)
  	{
  		int u, v;
  		cin>>u>>v;
  		
  		while(parent[u]!=u)
  		u=parent[u];
  	 
  	 while(parent[v]!=v)
  	 v=parent[v];
  	 
  		parent[v]=u;
  	}
  	
  	for(int i=1 ; i<=n ; i++)
  	{
  		int j=i;
  		while(parent[j]!=j)
  		j=parent[j];
  		
  		s.insert(j);
  	}
  	
  	cout<<"Case "<<t++<<": "<<s.size()<<endl;
  	s.clear();
  }

  return 0;
}
