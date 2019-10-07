#include<bits/stdc++.h>
using namespace std;

#define PII pair<int, int>

int a[800005];
map<int, int>m;

int main()
{
//	freopen("output.txt", "w", stdout);
	int t;
	cin>>t;

	while(t--)
	{
		m.clear();
		int n;
		cin>>n;

		int maxi=0;
		for(int i=0, j=0 ; i<n ; i++)
		{
			cin>>a[i];

			map<int, int>::iterator it=m.find(a[i]);

			if(it==m.end())
				m[ a[i] ]=i;
			else
			{
				int temp=m[ a[i] ];
				int l=m.size();
				maxi=max(maxi, l);
				m[ a[i] ]=i;

//				cout<<"temp="<<temp<<endl;
				for(int k=j ; k<temp ; k++)
				{
//					cout<<"k="<<k<<" a[k]="<<a[k]<<endl;
					it=m.find(a[k]);
					m.erase(it);
				}
				j=temp+1;
			}

//			cout<<"map=";
//			for(auto w : m)
//				cout<<w.second<<" ";
//			cout<<endl;
		}
		int l=m.size();
		maxi=max(maxi, l);

		cout<<maxi<<endl;
	}

}
