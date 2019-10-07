#include<bits/stdc++.h>
using namespace std;
long long int t,m,n,x;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		x=m-1+m*(n-1);
		if(x%2!=0)
		cout<<"Hasan"<<endl;
		else
		cout<<"Hussain"<<endl;
	}
}
