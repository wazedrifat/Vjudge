#include<bits/stdc++.h>
using namespace std;
int i,j,n,a,b;
string s;
int main()
{
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>s;
		for(j=0;j<n;j++)
   	if(s[j]=='X')
   	{
   		a=i;
   		b=j;
   	}
	}
	cout<<a<<","<<b;
}
