#include<bits/stdc++.h>
using namespace std;

#define MX 30
#define yes printf("Ordering is possible.\n");
#define no {printf("The door cannot be opened.\n");f=1;}
#define PII pair<int, int>

vector<int>g[MX];
int indegree[MX], outdegree[MX];
int visited[MX], exist[MX];

void DFS(int v)
{
	visited[v]=1;
	for(auto w : g[v])
	if(!visited[w])
		DFS(w);
}

PII HasDirectedEulerPath()//
{
	vector<int>v;
	PII p(-1, -1);

	for(int i=0 ; i<30 ; i++)
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

int main()
{
	//freopen("input.txt", "r", stdin);
	int t;
	scanf("%d", &t);

	while(t--)
	{
		for(int i=0 ; i<MX ; i++)
		{
			visited[i]=exist[i]=indegree[i]=outdegree[i]=0;
			g[i].clear();
		}

		int n;
		scanf("%d", &n);

		for(int i=0 ; i<n ; i++)
		{
			char ch[1005];
			scanf("%s", ch);

			int x=ch[0]-'a', y=ch[ strlen(ch)-1 ]-'a';
			g[x].push_back(y);

			exist[x]=exist[y]=1;
			indegree[y]++;
			outdegree[x]++;
		}

		int f=0;
		PII p=HasDirectedEulerPath();

		if( p==PII(-1, -1) )
		{
			printf("The door cannot be opened.\n");
			continue;
		}

		DFS(p.first);

//		cout<<"p="<<p.first<<","<<p.second<<endl;

//		for(int i=0 ; i<MX ; i++)
//			cout<<"i="<<i<<" "<<visited[i]<<" "<<exist[i]<<endl;

		for(int i=0 ; i<MX ; i++)
		if(!visited[i] && exist[i])
		{

			printf("The door cannot be opened.\n");
			f=1;
			break;
		}

		if(!f)
			printf("Ordering is possible.\n");
	}
}
