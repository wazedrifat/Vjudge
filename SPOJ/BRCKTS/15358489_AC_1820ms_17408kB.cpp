#include<bits/stdc++.h>
using namespace std;

#define MX 30005

class PII
{
public:
	int op, cl;
	PII(int a=0, int b=0)
	{
		op=a;	cl=b;
	}
	PII(char c)
	{
		op=0;	cl=0;
		if(c=='(')	op=1;
		else		cl=1;
	}

	PII operator+(const PII& p)
	{
		int m=min(op, p.cl);
		return PII(op+p.op-m, cl+p.cl-m);
	}

	void change()
	{
		swap(op, cl);
	}

	bool ok()
	{
		return (op==0 && cl==0);
	}

}SegTree[4*MX];
string s;

ostream &operator<<(ostream& ct, const PII& p)
{
	ct<<"("<<p.op<<", "<<p.cl<<")";
}

void init(int low, int high, int pos=0)	//	O(n)
{
	if(low==high)
	{
		SegTree[pos]=PII( s[low] );
		return ;
	}

	int mid=(low+high)/2;
	init(low, mid, 2*pos+1);
	init(mid+1, high, 2*pos+2);

	SegTree[pos]=SegTree[2*pos+1] + SegTree[2*pos+2];
//	cout<<"low="<<low<<" high="<<high<<" pos="<<pos<<" SegTree="<<SegTree[pos]<<"="<<SegTree[2*pos+1]<<"+"<<SegTree[2*pos+2]<<endl;
}

void Update(int low, int high, int Q, int pos=0)	//O(logn)
{
	if(Q>high || Q<low || low>high)	return;
	if(Q==low && low==high)
	{
//		cout<<"base 2 : "<<SegTree[pos]<<endl;
		SegTree[pos].change();
//		cout<<"base 2 : "<<SegTree[pos]<<endl;
		return;
	}

	int mid=(low+high)/2;

	Update(low, mid, Q, 2*pos+1);
	Update(mid+1, high, Q, 2*pos+2);

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
	int n, m, t=1;
	while(cin>>n)
	{
		cin>>s>>m;

		init(0, n-1);
//		print(n);
		cout<<"Test "<<t++<<":\n";
		while(m--)
		{
			int x;
			cin>>x;

			if(!x)
				if(SegTree[0].ok())	cout<<"YES\n";
				else				cout<<"NO\n";
			else	Update(0, n-1, x-1);
//			print(n);
		}

	}
}
