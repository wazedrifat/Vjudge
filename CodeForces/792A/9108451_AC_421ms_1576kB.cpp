#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
int n,i,j,k,a,b,c=0;
vector<int>v;
int main()
{
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	b=v[1]-v[0];
	for(i=1,c=1;i<v.size()-1;i++)
	{
		if(v[i+1]-v[i]<b)
		{
			b=v[i+1]-v[i];
			c=1;	
		}
		else if(v[i+1]-v[i]==b)
			c++;
	}
	cout<<b<<" "<<c;
}