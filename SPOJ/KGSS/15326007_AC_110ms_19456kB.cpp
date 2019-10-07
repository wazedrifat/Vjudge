#include<bits/stdc++.h>
using namespace std;

#define MX 100005
#define PII pair<int, int>

PII SegTree[4*MX];
int a[MX];

PII maximum(int a, int b)
{
	return PII( max(a, b) , min(a, b) );
}

PII maximum(PII a, PII b)
{
	return PII( max(a.first, b.first) , max( max(a.second, b.second) , min(a.first, b.first) ) );
}

ostream &operator<<(ostream& ct, const PII& p)
{
	ct<<"("<<p.first<<", "<<p.second<<")";
}

void init(int low, int high, int pos=0)	//	O(n)
{
	if(low==high)
	{
		SegTree[pos]=PII(a[low], -1);
		return ;
	}

	int mid=(low+high)/2;
	init(low, mid, 2*pos+1);
	init(mid+1, high, 2*pos+2);

	SegTree[pos]=maximum(SegTree[2*pos+1],SegTree[2*pos+2]);
}

PII Query(int low, int high, int Qlow, int Qhigh, int pos=0)	//O(logn)
{
	if(Qlow>high || Qhigh<low || low>high)	return PII(-1, -1);
	if(Qlow<=low && Qhigh>=high)	return SegTree[pos];

	int mid=(low+high)/2;
	PII x=Query(low, mid, Qlow, Qhigh, 2*pos+1);
	PII y=Query(mid+1, high, Qlow, Qhigh, 2*pos+2);

	return maximum(x,y);
}

void Update(int low, int high, int Q, int val, int pos=0)	//O(logn)
{
	if(Q>high || Q<low || low>high)	return;
	if(Q==low && low==high)
	{
		SegTree[pos]=PII(val, -1);
		return;
	}

	int mid=(low+high)/2;

	Update(low, mid, Q, val, 2*pos+1);
	Update(mid+1, high, Q, val, 2*pos+2);

	SegTree[pos]=maximum(SegTree[2*pos+1], SegTree[2*pos+2]);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int n, q;
	scanf("%d", &n);

	for(int i=0 ; i<n ; i++)
		scanf("%d", &a[i]);
	init(0, n-1);

	scanf("%d", &q);
	while(q--)
	{
		char ch;
		int x, y;
		cin>>ch>>x>>y;

//		cout<<"c="<<ch<<" x="<<x<<" y="<<y<<endl;
		x--;	y--;

		if(ch=='U')	Update(0, n-1, x, y+1);
		else
		{
			PII p=Query(0, n-1, x, y);

			cout<<p.first+p.second<<endl;
		}
	}
}
