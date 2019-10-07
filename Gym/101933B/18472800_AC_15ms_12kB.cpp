#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, f=1;
    cin>>n;

    for(int i=1 ; i<=n ; i++)
	{
		string s;
		cin>>s;
		if(s=="mumble")	continue;

		stringstream ss;
		ss<<s;

		int x;
		ss>>x;

//		cout<<"x="<<x<<endl;
		if(x!=i)	f=0;
	}

	if(f)   cout<<"makes sense";
	else	cout<<"something is fishy";
}
