#include<bits/stdc++.h>
using namespace std;

#define MX 200005

bool f[1005];

int main()
{
	int n, m, u, v, u1, v1;
	cin>>n>>m;

	for(int i=0 ; i<m ; i++)
	{
		cin>>u>>v;
		f[u]=f[v]=1;

		if(!i)
		{
			u1=u;	v1=v;
		}
	}

	int save=-1;
	for(int i=1 ; i<=n ; i++)
	if(f[i]!=1)
	{
		save=i;
		break;
	}

	if(save==-1 && n==4)
	{
		cout<<4<<endl;
		cout<<u<<" "<<u1<<endl;
		cout<<v<<" "<<v1<<endl;
		cout<<u1<<" "<<v<<endl;
		cout<<u<<" "<<v1<<endl;
		return 0;
	}

	cout<<n-1<<endl;

	for(int i=1 ; i<=n ; i++)
	if(i!=save)
		cout<<save<<" "<<i<<endl;
}
