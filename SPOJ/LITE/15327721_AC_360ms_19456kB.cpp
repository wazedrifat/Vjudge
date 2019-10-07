#include<bits/stdc++.h>
using namespace std;

#define MX 100005

int SegTree[4*MX], Lazy[4*MX];

int Query(int low, int high, int Qlow, int Qhigh, int pos=0)	//O(logn)
{
	if(Lazy[pos]&1)
	{
		SegTree[pos]=high-low+1-SegTree[pos];
		if(low!=high)//not a leaf node
		{
			Lazy[2*pos+1]+=Lazy[pos];
			Lazy[2*pos+2]+=Lazy[pos];
		}
	}
	Lazy[pos]=0;

	if(Qlow>high || Qhigh<low || low>high)	return 0;
	if(Qlow<=low && Qhigh>=high)	return SegTree[pos];

	int mid=(low+high)/2;
	int x=Query(low, mid, Qlow, Qhigh, 2*pos+1);
	int y=Query(mid+1, high, Qlow, Qhigh, 2*pos+2);

	return x+y;
}

void Update(int low, int high, int Qlow, int Qhigh, int pos=0)	//O(logn)
{
	if(Lazy[pos]&1)
	{
		SegTree[pos]=high-low+1-SegTree[pos];
		if(low!=high)//not a leaf node
		{
			Lazy[2*pos+1]++;
			Lazy[2*pos+2]++;
		}
	}
	Lazy[pos]=0;

	if(Qlow>high || Qhigh<low || low>high)	return;
	if(Qlow<=low && Qhigh>=high)
	{
		SegTree[pos]=high-low+1-SegTree[pos];
		if(low!=high)//not a leaf node
		{
			Lazy[2*pos+1]++;
			Lazy[2*pos+2]++;
		}
//		cout<<"low="<<low<<" high="<<high<<" pos="<<pos<<" SegTree="<<SegTree[pos]<<endl;
		return;
	}

	int mid=(low+high)/2;

	Update(low, mid, Qlow, Qhigh, 2*pos+1);
	Update(mid+1, high, Qlow, Qhigh, 2*pos+2);

	SegTree[pos]=SegTree[2*pos+1] + SegTree[2*pos+2];
//	cout<<"low="<<low<<" high="<<high<<" pos="<<pos<<" SegTree="<<SegTree[pos]<<"="<<SegTree[2*pos+1]<<"+"<<SegTree[2*pos+2]<<endl;
}

//void print(int n)
//{
//	cout<<"SegTree: ";
//	for(int i=0 ; i<4*n ; i++)
//		cout<<SegTree[i]<<" ";
//	cout<<endl;
//
//	cout<<"Lazy : ";
//	for(int i=0 ; i<4*n ; i++)
//		cout<<Lazy[i]<<" ";
//	cout<<endl;
//
//	cout<<"Querry : ";
//	for(int i=0 ; i<n ; i++)
//		cout<<Query(0, n-1, i, i)<<" ";
//	cout<<endl<<endl;;
//}

int main()
{
	//freopen("input.txt", "r", stdin);

	int n, m;
	scanf("%d %d", &n, &m);

	while(m--)
	{
		int t, a, b;
		scanf("%d %d %d", &t, &a, &b);
		a--;	b--;

		if(!t)	Update(0, n-1, a, b);
		else	printf("%d\n", Query(0, n-1, a, b));
//		print(n);
	}
}
