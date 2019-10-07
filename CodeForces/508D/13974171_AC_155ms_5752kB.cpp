#include<bits/stdc++.h>
using namespace std;

#define MX 100005
#define PII pair<int, int>

vector<string>str;
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

	for(int i=0 ; i<str.size() ; i++)
	if(outdegree[i]!=indegree[i])
	v.push_back(i);

	if(v.size()==2)
	if(outdegree[ v[0] ]-indegree[ v[0] ]==1 && indegree[ v[1] ]-outdegree[ v[1] ]==1)
		p=PII( v[0], v[1] );
	else if(outdegree[ v[1] ]-indegree[ v[1] ]==1 && indegree[ v[0] ]-outdegree[ v[0] ]==1)
		p=PII( v[1], v[0] );

	if(!v.size())
	return PII(0, 0);

	v.clear();
	return p;
}

deque<int>circuit, CurPath;
void HierHolzar(int start)
{
	int EdgeCount[str.size()];

	for(int i=0 ; i<str.size() ; i++)
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
	multimap<string, int>m;
	int rnk=0;

	int n, start=0;
	scanf("%d", &n);

	for(int i=0 ; i<n ; i++)
	{
		int x, y;
		char ch[10];
		scanf("%s", ch);
		string s=ch;
		string s1(s.begin(), s.begin()+2);
		string s2(s.begin()+1, s.begin()+3);

		map<string, int>::iterator it=m.find(s1);

		if(it==m.end())
		{
			m.insert( make_pair(s1, rnk) );
			str.push_back(s1);
			x=rnk++;
		}
		else	x=it->second;

		it=m.find(s2);
		if(it==m.end())
		{
			m.insert( make_pair(s2, rnk) );
			str.push_back(s2);
			y=rnk++;
		}
		else	y=it->second;

		g[x].push_back(y);

		indegree[y]++;
		outdegree[x]++;
	}
	PII p=HasDirectedEulerPath();
	if( p==PII(-1, -1) )
	{
		printf("NO\n");
		return 0;
	}

	int flag=0;
	bool f=path();

	DFS(p.first);
	for(int i=0 ; i<str.size() ; i++)
	if(!visited[i])
	{
		printf("NO\n");
		return 0;
	}

	HierHolzar(p.first);
	printf("YES\n");

	cout<<str[ circuit[0] ][0];
	for(int i=0 ; i<circuit.size() ; i++)
	cout<<str[ circuit[i] ][1];
}
