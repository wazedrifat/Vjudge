#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		char c[20000];
        int n, m, K;
        cin>>n>>m>>K;

		int k=K;
        for(int i=1 ; i<=n ; i++)
			cin>>c[i];

		int cnt=0;
		for(int i=0 ; i<m ; i++)
		{
			char ch;
			cin>>ch;

			if(ch=='A')
			{
				k=n;
				continue;
			}

			int x;
			cin>>x;

			cnt+=( K>=x || (k>=x && c[x]=='S') );
//			cout<<"k="<<k<<" c="<<c[x]<<" cnt="<<cnt<<endl;
			k=max(k, x);
		}
		cout<<cnt<<endl;
	}

}
