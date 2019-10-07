#include<bits/stdc++.h>
#include<vector>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main()
{
	int i,j,k,n,c=0;
	cin>>n;
	vector<int>g;
	for(i=0;i<n;i++)
	{
		cin>>k;
		g.push_back(k);
	}
	sort(g.begin(),g.end());
	k=n/2+1;
	for(i=0;i<k;i++)
		c+=g[i]/2+1;
	cout<<c;
}
