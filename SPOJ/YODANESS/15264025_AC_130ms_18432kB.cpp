#include<bits/stdc++.h>
using namespace std;

#define MX 30001
int a[MX], SegTree[4*MX], Lazy[4*MX];

void update(int low, int high, int Qhigh, int pos=0, int Qlow=0)
{
	if(Qlow>high || Qhigh<low || low>high)	return;

	if(Lazy[pos])
	{
		SegTree[pos]+=Lazy[pos];
		if(low!=high)
		{
			Lazy[2*pos+1]+=Lazy[pos];
			Lazy[2*pos+2]+=Lazy[pos];
		}
		Lazy[pos]=0;
	}

	if(Qlow<=low && Qhigh>=high)
	{
		SegTree[pos]++;
		if(low!=high)
		{
			Lazy[2*pos+1]++;
			Lazy[2*pos+2]++;
		}
		return;
	}

	int mid=(low+high)/2;

	update(low, mid, Qhigh, 2*pos+1);
	update(mid+1, high, Qhigh, 2*pos+2);
}

int Query(int low, int high, int Q, int pos=0)
{
	if(Lazy[pos])
	{
		SegTree[pos]+=Lazy[pos];
		if(low!=high)
		{
			Lazy[2*pos+1]+=Lazy[pos];
			Lazy[2*pos+2]+=Lazy[pos];
		}
		Lazy[pos]=0;
	}

	if(low==high && low==Q)	return SegTree[pos];

	int mid=(low+high)/2;

	if(Q>=low && Q<=mid)	return Query(low, mid, Q, 2*pos+1);
	else					return Query(mid+1, high, Q, 2*pos+2);
}

void print(int n)
{
//	cout<<"print : ";
//	for(int i=0 ; i<n ; i++)
//	cout<<Query(0, n, i)<<" ";
//	cout<<endl;

	cout<<"Tree : ";
	for(int i=0 ; i<15 ; i++)
		cout<<SegTree[i]<<" ";
	cout<<endl;

}

int main()
{
	//freopen("input.txt", "r", stdin);

	map<string, int>m;
	int t, res[MX];
	cin>>t;

	while(t--)
	{
		memset(SegTree, 0, sizeof SegTree);
		memset(Lazy, 0, sizeof Lazy);
		m.clear();

		int n, sum=0;
		cin>>n;

		for(int i=0 ; i<n ; i++)
		{
			string s;
			cin>>s;
			m[s]=i;
		}

		for(int i=0 ; i<n ; i++)
		{
			string s;
			cin>>s;

			//cout<<" num= "<<m[s]<<" ";
			//print(n);

			sum+=Query(0, n-1, m[s]);
			update(0, n-1, m[s]-1);

			//print(n);cout<<endl;
		}
		//cout<<"res=";
		cout<<sum<<endl;
	}
}
