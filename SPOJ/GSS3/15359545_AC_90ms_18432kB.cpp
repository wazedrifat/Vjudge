#include<bits/stdc++.h>
using namespace std;

#define MX 50005

int a[MX];
class PowerRanger
{
public:
	int TotalSum, PrefixSum, SuffixSum, MaxSum;
	PowerRanger(int t, int p, int s, int m)
	{
		TotalSum=t;	PrefixSum=p;	SuffixSum=s;	MaxSum=m;
	}
	PowerRanger(int v=0)
	{
		TotalSum=PrefixSum=SuffixSum=MaxSum=v;
	}

	PowerRanger operator+(const PowerRanger& pr)
	{
		int t=TotalSum+pr.TotalSum;
		int p=max(PrefixSum, TotalSum+pr.PrefixSum);
		int s=max(pr.SuffixSum, SuffixSum+pr.TotalSum);
		int m=max(SuffixSum+pr.PrefixSum, max(MaxSum, pr.MaxSum) );

		return PowerRanger(t, p, s, m);
	}

}SegTree[4*MX];
string s;

ostream &operator<<(ostream& ct, const PowerRanger& p)
{
	ct<<"("<<p.TotalSum<<", "<<p.PrefixSum<<", "<<p.SuffixSum<<", "<<p.MaxSum<<")";
}

void init(int low, int high, int pos=0)	//	O(n)
{
	if(low==high)
	{
		SegTree[pos]=PowerRanger( a[low] );
		return ;
	}

	int mid=(low+high)/2;
	init(low, mid, 2*pos+1);
	init(mid+1, high, 2*pos+2);

	SegTree[pos]=SegTree[2*pos+1] + SegTree[2*pos+2];
//	cout<<"low="<<low<<" high="<<high<<" pos="<<pos<<" SegTree="<<SegTree[pos]<<"="<<SegTree[2*pos+1]<<"+"<<SegTree[2*pos+2]<<endl;
}

PowerRanger Query(int low, int high, int Qlow, int Qhigh, int pos=0)	//O(logn)
{
	if(Qlow>high || Qhigh<low || low>high)	return PowerRanger(-10005);
	if(Qlow<=low && Qhigh>=high)	return SegTree[pos];

	int mid=(low+high)/2;
	PowerRanger x=Query(low, mid, Qlow, Qhigh, 2*pos+1);
	PowerRanger y=Query(mid+1, high, Qlow, Qhigh, 2*pos+2);

//	cout<<"low="<<low<<" high="<<high<<" pos="<<pos<<" return : "<<x+y<<"="<<x<<"+"<<y<<endl;
	return x+y;
}

void Update(int low, int high, int Q, int val, int pos=0)	//O(logn)
{
	if(Q>high || Q<low || low>high)	return;
	if(Q==low && low==high)
	{
		SegTree[pos]=PowerRanger( val );
//		cout<<"Seg="<<SegTree[pos]<<endl;
		return;
	}

	int mid=(low+high)/2;

	Update(low, mid, Q, val, 2*pos+1);
	Update(mid+1, high, Q, val, 2*pos+2);

	SegTree[pos]=SegTree[2*pos+1] + SegTree[2*pos+2];
//	cout<<"low="<<low<<" high="<<high<<" pos="<<pos<<" SegTree="<<SegTree[pos]<<"="<<SegTree[2*pos+1]<<"+"<<SegTree[2*pos+2]<<endl;
}

void print(int n)
{
	cout<<"SegTree: ";
	for(int i=0 ; i<4*n ; i++)
		cout<<SegTree[i]<<" ";
	cout<<endl;
	cout<<endl;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int n;
	cin>>n;

	for(int i=0 ; i<n ; i++)
		cin>>a[i];

	init(0, n-1);

//	print(n);
	int m;
	cin>>m;

	while(m--)
	{
		int t, x, y;
		cin>>t>>x>>y;

		if(!t)	Update(0, n-1, x-1, y);
		else	cout<<Query(0, n-1, x-1, y-1).MaxSum<<endl;
//		print(n);
	}

}
