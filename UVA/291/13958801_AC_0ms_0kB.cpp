#include<bits/stdc++.h>
using namespace std;

#define PII pair<int, int>

vector<int>g[6];
set<PII>visited;

void PrintPath(deque<int>d)
{
	int u=d.back();

	for(auto w : g[u])
	if(visited.find( PII(u, w) )==visited.end() )
	{
		visited.insert( PII(u, w) );
		visited.insert( PII(w, u) );
		d.push_back(w);
		PrintPath(d);
		if(d.size()==8)
		{
			for(auto v : d)
			cout<<v;
			cout<<2<<endl;
		}
		d.pop_back();
		visited.erase( PII(u, w) );
		visited.erase( PII(w, u) );
	}
}

int main()
{
	int n=5, m=8;
	g[1].push_back(2);
	g[1].push_back(3);
	g[1].push_back(5);
	g[2].push_back(1);
	g[2].push_back(3);
	g[2].push_back(5);
	g[3].push_back(1);
	g[3].push_back(2);
	g[3].push_back(4);
	g[3].push_back(5);
	g[4].push_back(3);
	g[4].push_back(5);
	g[5].push_back(1);
	g[5].push_back(2);
	g[5].push_back(3);
	g[5].push_back(4);

	deque<int>d;
	d.push_back(1);

	PrintPath(d);
}
