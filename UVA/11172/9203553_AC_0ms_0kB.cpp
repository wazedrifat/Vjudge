#include <bits/stdc++.h>
using namespace std;
long long int n,i,x,y;
int main()
{
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x>>y;
		if(x==y)
		cout<<"="<<endl;
		else if(x<y)
		cout<<"<"<<endl;
		else
		cout<<">"<<endl;
	}
}
