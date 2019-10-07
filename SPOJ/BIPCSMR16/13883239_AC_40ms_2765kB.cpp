#include<bits/stdc++.h>
using namespace std;

#define file freopen("input.txt", "r", stdin);
#define CLOCK printf("time: %lld ms\n",(long long)clock()*1000/CLOCKS_PER_SEC);

//bool cmp(int a, int b)
//{
//	return a<b;
//}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		long long int a[3];
		cin>>a[0]>>a[1]>>a[2];

		sort(a, a+3);
//		cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
		cout<<min(a[0]+a[1], (a[0]+a[1]+a[2])/3 )<<endl;
	}
}
