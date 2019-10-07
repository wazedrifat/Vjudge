#include<bits/stdc++.h>
using namespace std;

#define int long long int
main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int a, k, x1, x2, x3;
		cin>>a>>k>>x1>>x2>>x3;

		int l=min(x1, min(x2, x3)), h=max(x1, max(x2, x3));

		int res=min(a, l-h+2*k+a)*a;
//		cout<<"res="<<res<<"=min ->"<<a*a<<" - "<<(x-y)*a<<endl;
		res=max((int)0, res);
		res=min(a*a, res);

		cout.precision(3);
//		printf("%lf %lf %lf\n\n", res, x, y);
		cout<<fixed<<(double)res<<endl;
	}
}
