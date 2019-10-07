#include<bits/stdc++.h>
using namespace std;

#define PII pair<int, int>

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		PII maxi[4]={ PII(INT_MAX, INT_MIN), PII(INT_MAX, INT_MIN), PII(INT_MAX, INT_MIN), PII(INT_MAX, INT_MIN)};
		int n;
		cin>>n;

		while(n--)
		{
			int c, l, x;
			cin>>c>>l>>x;
\
			if(x>maxi[l].second)	maxi[l]=PII( c , x);
			else if(x==maxi[l].second)	maxi[l].first=min(c, maxi[l].first);
		}

		for(int i=1 ; i<=3 ; i++)
			cout<<maxi[i].second<<" "<<maxi[i].first<<endl;
	}
}
