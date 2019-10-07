#include<bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
map<int, int>m;
vector<int>v;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		m.clear();
		v.clear();
		int n;
		cin>>n;

		for(int i=0 ; i<n ; i++)
		{
			int u, v;
			cin>>u>>v;

			map<int, int>::iterator it=m.find(u);
			if(it==m.end())	m[u]=v;
			else m[u]=max(m[u], v);
		}

		for(auto it : m)		v.push_back(it.second);
		sort(v.begin(), v.end());

		int l=v.size();
		if(l<3)	cout<<0<<endl;
		else	cout<<v[l-1]+v[l-2]+v[l-3]<<endl;
	}
}
