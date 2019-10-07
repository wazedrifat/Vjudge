#include<bits/stdc++.h>
using namespace std;

#define PII pair<int, int>

int m, n, tmm, c[105];
PII a[105];

bool cmp(PII x, PII y)
{
//	return x.first+c[ x.second ]<y.first+c[ y.second ];
	if(x.first<y.first)			return 1;
	else if(x.first==y.first)	return x.first+c[ x.second ]<=y.first+c[ y.second ];
	else						return 0;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	while(scanf("%d %d %d", &m, &n, &tmm)!=EOF)
	{
		for(int i=0 ; i<n ; i++)
			cin>>c[i];

		for(int i=0 ; i<n ; i++)
			a[i]=PII(0, i);
		sort(a, a+n, cmp);

		int cnt=0;
		while(cnt<m && a[0].first<tmm)
		{
//			cout<<"array=";
//			for(int i=0 ; i<n ; i++)
//				cout<<"("<<a[i].first<<","<<a[i].second<<") ";
//			cout<<endl;

			cnt++;
			a[0].first+=c[ a[0].second ];
			sort(a, a+n, cmp);
//			cout<<"cnt="<<cnt<<" m="<<m<<" a="<<a[0].first<<" tmm="<<tmm<<endl;
		}

//		cout<<"1 array=";
//		for(int i=0 ; i<n ; i++)
//			cout<<"("<<a[i].first<<","<<a[i].second<<") ";
//		cout<<endl;

		sort(a, a+n);

//		cout<<"2 array=";
//		for(int i=0 ; i<n ; i++)
//			cout<<"("<<a[i].first<<","<<a[i].second<<") ";
//		cout<<endl;

//		cout<<"cnt="<<cnt<<endl;
		int cc=0;
		for(int i=0 ; i<n ; i++)
			if(a[i].first<=tmm)		cc+=a[i].first/c[ a[i].second ];
			else					cc+=a[i].first/c[ a[i].second ]-1;

//		cout<<"cc="<<cc<<endl;
		cout<<m-cnt<<" "<<cnt-cc<<endl;
	}
}
