#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n, x, y;
		cin>>n>>x>>y;

        n/=2;

        if( (x>n && y>=n)  )	cout<<"YES"<<endl;
        else	cout<<"NO"<<endl;
	}
}
