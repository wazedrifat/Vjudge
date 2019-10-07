//wazed rifat
#include<bits/stdc++.h>
using namespace std;
int i,n,s,s1,p,q;
int main()
{
	cin>>n;
	int a[n];
	for(i=0,s=0;i<n;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	cin>>p>>q;
	for(i=p-1,s1=0;;i++)
	{
		
		if(i==n)
		i=0;
		if(i==q-1)
		break;
		s1+=a[i];
	}
	cout<<min(s-s1,s1);
}
