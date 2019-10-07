#include<bits/stdc++.h>
using namespace std;

int n, r;
vector<int>v;

int main()
{

	while(cin>>n>>r && (n || r) )
	{
		int m=max(r, n-r)+1, k=min(r, n-r);


		v.clear();
		for(int i=2 ; i<=k ; i++)	v.push_back(i);

		int res=1;
		for(int i=m ; i<=n ; i++)
		{
			int val=i;
			for(int j=0 ; j<v.size() ; j++)
			{
				if(val%v[j]==0)
				{
					val/=v[j];
					v.erase(v.begin()+j);
					j--;
				}
				else
				{
					int g=__gcd(val, v[j]);
					val/=g;
					v[j]/=g;
				}
			}
			res*=val;
		}

		cout<<res<<endl;
	}
}
