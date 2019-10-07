#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int> 

int main()
{
  int n, m, t=1;
  int parent[500000];
  int rank[500000];
  
  cin>>t;
  
  while(t--)
  {
  	cin>>n>>m;
  	
  	for(int i=0 ; i<=n ; i++)
  	{
  		parent[i]=i;
  		rank[i]=1;
  	}
  	
  	for(int i=0 ; i<m ; i++)
  	{
  		int u, v;
  		cin>>u>>v;
  		
  		while(parent[u]!=u)
  		u=parent[u];
  	 
  	 while(parent[v]!=v)
  	 v=parent[v];
  	 
  	 if(u!=v)
  	// cout<<"1. u="<<u<<" v="<<v<<" rnk="<<rank[u]<<" "<<rank[v]<<endl;
  	 
   	rank[u]+=rank[v];
   	parent[v]=u;
  	
   //	cout<<"2. u="<<u<<" v="<<v<<" rnk="<<rank[u]<<" "<<rank[v]<<endl;
  	}
  	
  	int cnt=INT_MIN;
  	for(int i=1 ; i<=n ; i++)
  	{
  		cnt=max(cnt, rank[i]);
  	//	cout<<"i="<<i<<" rnk="<<rank[i]<<endl;
  	}
  	
  	cout<<cnt<<endl;
  }

  return 0;
}
