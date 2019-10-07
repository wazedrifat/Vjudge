#include<bits/stdc++.h>
using namespace std;

int dif(int a[], int b[])
{
	int cnt=0;
	for(int i=0 ; i<7 ; i++)
		cnt+=(a[i]!=b[i]);
	return cnt;
}

bool check(int a[])
{
	bool x=( (a[0]+a[2]+a[3])%2 == a[5] );
	bool y=( (a[1]+a[2]+a[3])%2 == a[4] );
	bool z=( (a[1]+a[0]+a[3])%2 == a[6] );

//	cout<<"x="<<x<<" y="<<y<<" z="<<z<<endl;
	return (x && y && z);
}

void Set(int a[])
{
	a[5]=(a[0]+a[2]+a[3])%2;
	a[4]=(a[1]+a[2]+a[3])%2;
	a[6]=(a[1]+a[0]+a[3])%2;
}

int main()
{
	int a[7], b[7];
	for(int i=0 ; i<7 ; i++)
		cin>>a[i];

	if( check(a) )
	{
		for(int i=0 ; i<7 ; i++)
			cout<<a[i]<<" ";
		return 0;
	}

	for(int i=0 ; i<16 ; i++)
	{
		int dig[7];

		for(int i=0 ; i<7 ; i++)	dig[i]=0;

		int m=i, j=0;
		while(m)
		{
			dig[j++]=m%2;
			m/=2;
		}

		Set(dig);
		if(check(dig) && dif(a, dig)<=1)
		{
			for(int i=0 ; i<7 ; i++)
				cout<<dig[i]<<" ";
			return 0;
		}
	}
}
