#include<bits/stdc++.h>
using namespace std;

#define MX 1000005

class Div
{
public:
	int zero, one, two;
	Div(int a=1, int b=0, int c=0)
	{
		zero=a;	one=b;	two=c;
	}

	void change(int t=1)//swap
	{
		t%=3;
		while(t--)
		{
			int temp=two;
			two=one;
			one=zero;
			zero=temp;
		}
	}

	Div operator+(const Div& d)
	{
		return Div(zero+d.zero, one+d.one, two+d.two);
	}
};

ostream &operator<<(ostream &os, const Div& d) {
    os <<"("<<d.zero<<", "<<d.one<<", "<<d.two<<")";
}

Div SegTree[4*MX];
int Lazy[4*MX];

void init(int low, int high, int pos=0)	//	O(n)
{
	//cout<<"low="<<low<<" high="<<high<<" pos="<<pos<<endl;
	if(low==high)	return;

	int mid=(low+high)/2;
	init(low, mid, 2*pos+1);
	init(mid+1, high, 2*pos+2);

	//cout<<"low="<<low<<" high="<<high<<" sSegTree["<<pos<<"]="<<SegTree[2*pos+1]<<" + "<<SegTree[2*pos+2]<<" = "<<SegTree[2*pos+1] + SegTree[2*pos+2]<<endl;
	SegTree[pos]=SegTree[2*pos+1] + SegTree[2*pos+2];
}

int Query(int low, int high, int Qlow, int Qhigh, int pos=0)	//O(logn)
{
//	cout<<"low="<<low<<" high="<<high<<" pos="<<pos<<" Lazy="<<Lazy[pos]<<endl;

	if(Lazy[pos]%3)
	{
		SegTree[pos].change(Lazy[pos]);

		if(low!=high)//not a leaf node
		{
			Lazy[2*pos+1]+=Lazy[pos];
			Lazy[2*pos+2]+=Lazy[pos];
		}
	}
	Lazy[pos]=0;

	if(Qlow>high || Qhigh<low || low>high)	return 0;

	if(Qlow<=low && Qhigh>=high)
	{
//		cout<<"SegTree["<<pos<<"]="<<SegTree[pos]<<" left="<<SegTree[2*pos+1]<<" right="<<SegTree[2*pos+2]<<endl;
		return SegTree[pos].zero;
	}

	int mid=(low+high)/2;
	int x=Query(low, mid, Qlow, Qhigh, 2*pos+1);
	int y=Query(mid+1, high, Qlow, Qhigh, 2*pos+2);

	//SegTree[pos]=SegTree[2*pos+1] + SegTree[2*pos+2];
//	cout<<"low="<<low<<" high="<<high<<" pos="<<pos<<" res="<<x<<"+"<<y<<"="<<x+y<<endl;
	return x+y;
}

void Update(int low, int high, int Qlow, int Qhigh, int pos=0)	//O(logn)
{
	if(Lazy[pos]%3)
	{
//		cout<<"Lazy 	low="<<low<<"high="<<high<<" pos="<<pos<<" sg="<<SegTree[pos];
		SegTree[pos].change(Lazy[pos]);
//		cout<<" -> "<<SegTree[pos]<<endl;

		if(low!=high)//not a leaf node
		{
			Lazy[2*pos+1]+=Lazy[pos];
			Lazy[2*pos+2]+=Lazy[pos];
		}
	}
	Lazy[pos]=0;

	if(Qlow>high || Qhigh<low || low>high)	return;

	if(Qlow<=low && Qhigh>=high)
	{
//		cout<<"change		low="<<low<<"high="<<high<<" pos="<<pos<<" sg="<<SegTree[pos];
		SegTree[pos].change();
//		cout<<" -> "<<SegTree[pos]<<endl;

		if(low!=high)//not a leaf node
		{
			Lazy[2*pos+1]++;
			Lazy[2*pos+2]++;
		}
		return;
	}

	int mid=(low+high)/2;

	Update(low, mid, Qlow, Qhigh, 2*pos+1);
	Update(mid+1, high, Qlow, Qhigh, 2*pos+2);

	SegTree[pos]=SegTree[2*pos+1] + SegTree[2*pos+2];
//	cout<<"low="<<low<<" high="<<high<<" pos="<<pos<<" SegTree="<<SegTree[pos]<<endl;

}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

//	int test;cin>>test;
//	while(test--){memset(Lazy, 0, sizeof Lazy);

	int n, q;
	scanf("%d %d", &n, &q);

	init(0, n-1);

//	cout<<"SegTree : ";
//	for(int i=0 ; i<n ; i++)
//		cout<<Query(0, n-1, i, i);
//
//	cout<<"\nprint:";
//	for(int i=0 ; i<10 ; i++)
//		cout<<SegTree[i];
//	cout<<endl;

	while(q--)
	{
		int t, a, b;
		scanf("%d %d %d", &t, &a, &b);

		if(!t)	Update(0, n-1, a, b);
		else
		{
//			cout<<"\nres=";
			printf("%d\n", Query(0, n-1, a, b));
		}

//		cout<<"SegTree : ";
//			for(int i=0 ; i<n ; i++)
//				cout<<Query(0, n-1, i, i);
//
//		cout<<"Lazy:";
//		for(int i=0 ; i<25 ; i++)
//			cout<<Lazy[i]<<" ";
//
//		cout<<"\nprint:";
//		for(int i=0 ; i<25 ; i++)
//			cout<<SegTree[i];
//		cout<<endl;cout<<endl;
	}
//	}
}
