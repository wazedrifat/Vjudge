#include<bits/stdc++.h>
using namespace std;

#define PII pair<int, int>

int main()
{
	int n;
	unordered_map<int, int>m;
	vector<int>v;

	while(scanf("%d", &n)!=EOF)
	{
		if(m.find(n)==m.end())
		{
			m[n]=1;
			v.push_back(n);
		}
		else
			m[n]++;
	}

	for(auto w : v)
		cout<<w<<" "<<m[w]<<endl;
}
