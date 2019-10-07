#include<bits/stdc++.h>
using namespace std;

#define MX 30
#define PII pair<int, int>

vector<int>g[MX];
int indegree[MX], outdegree[MX];
int visited[MX], exist[MX];

void DFS(int v)
{
	visited[v]=1;
	for(int i=0 ; i<g[v].size() ; i++)
	if(!visited[ g[v][i]] )
		DFS( g[v][i] );
}

PII HasDirectedEulerPath()//
{
	vector<int>v;
	PII p(-1, -1);

	for(int i=0 ; i<MX ; i++)
	if(outdegree[i]!=indegree[i])
	v.push_back(i);

	if(v.size()==2)
	if(outdegree[ v[0] ]-indegree[ v[0] ]==1 && indegree[ v[1] ]-outdegree[ v[1] ]==1)
		p=PII( v[0], v[1] );
	else if(outdegree[ v[1] ]-indegree[ v[1] ]==1 && indegree[ v[0] ]-outdegree[ v[0] ]==1)
		p=PII( v[1], v[0] );

	if(!v.size())
	{
		for(int i=0 ; i<MX ; i++)
			if(exist[i])	return PII(i, i);
	}
	v.clear();
	return p;
}

deque<int>circuit, CurPath;
void HierHolzar(int start)
{
	circuit.clear();
	CurPath.clear();
	int EdgeCount[MX+2];

	for(int i=0 ; i<MX ; i++)
		EdgeCount[i]=g[i].size();

	CurPath.push_back(start);
	int CurV=start;

	while(CurPath.size())
	if(EdgeCount[CurV])
	{
		CurPath.push_back(CurV);
		int NextV=g[CurV].back();
		EdgeCount[CurV]--;
		g[CurV].pop_back();
		CurV=NextV;
	}
	else
	{
		circuit.push_front(CurV);
		CurV=CurPath.back();
		CurPath.pop_back();
	}
}

bool path()
{
	vector<int>v;
	PII p(-1, -1);

	for(int i=0 ; i<MX ; i++)
	if(outdegree[i]!=indegree[i])
	v.push_back(i);
	bool f=v.size();

	v.clear();
	return f;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int test;
	multimap<PII, string>m;
	scanf("%d", &test);

	for(int t=1 ; t<=test ; t++)
	{
		m.clear();
		for(int i=0 ; i<MX ; i++)
		{
			visited[i]=exist[i]=indegree[i]=outdegree[i]=0;
			g[i].clear();
		}

		int n, start=0;
		scanf("%d", &n);

		for(int i=0 ; i<n ; i++)
		{
			char ch[1005];
			scanf("%s", ch);
			string s=ch;

			int x=s[0]-'a';
			int y=s[ s.length()-1 ]-'a';
			g[x].push_back(y);

			m.insert( make_pair( make_pair(x, y), s) );
			//m.insert( make_pair( make_pair(y, x), s) );
			exist[x]=1;
			indegree[y]++;
			outdegree[x]++;
		}

//		cout<<"g : \n";
//		for(int i=0 ; i<MX ; i++)
//		{
//			cout<<"i="<<i<<" : ";
//			for(auto v : g[i])
//				cout<<v<<" ";
//			cout<<endl;
//		}

		PII p=HasDirectedEulerPath();
//		cout<<"p="<<p.first<<","<<p.second<<"  "<<path()<<endl;
		if( p==PII(-1, -1) )
		{
			printf("Case %d: No\n", t);
			continue;
		}

		DFS(start);
		int flag=0;

//		for(int i=0 ; i<MX ; i++)
//		{
//			cout<<(char)(exist[i]<<" "<<visited[i]<<endl;
//		if(exist[i] && !visited[i])
//		{
//			printf("Case %d: No\n", t);
//			flag=1;	break;
//		}
//		}
//
//		if(flag)	continue;


		bool f=path();

		//if(f)
		//g[p.second].push_back(p.first);



		HierHolzar(p.first);

		if(circuit.size()!=n+1)
		{
			//cout<<"size="<<circuit.size()<<endl;
			printf("Case %d: No\n", t);
			continue;
		}
//		cout<<circuit.size()<<endl;

//		cout<<"circuit : ";
//		for(int i=1 ; i<circuit.size() ; i++)
//			cout<<circuit[i]<<" ";
//		cout<<endl;
//
//		cout<<"map : ";
//		for(auto mp : m)
//			cout<<mp.second<<" ";
//		cout<<endl;
		printf("Case %d: Yes\n", t);
		for(int i=1 ; i<circuit.size() ; i++)
		{
			multimap<PII, string>::iterator it=m.find( PII(circuit[i-1], circuit[i]) );

			//if(it!=m.end())
			cout<<it->second;
			if(i<circuit.size()-1)
				cout<<" ";
			m.erase(it);
		}
		cout<<endl;
//		cout<<"ok2";
	}
}
