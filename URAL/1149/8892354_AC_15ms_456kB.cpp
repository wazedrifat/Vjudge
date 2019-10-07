#include<bits/stdc++.h>
#include<vector>
#include<stdlib.h>
#include<string.h>
using namespace std;
int i,j,k,x;
int main()
{
	cin>>x;
	for(i=1;i<x;i++)
		cout<<"(";
	for(i=1;i<=x;i++)
	{
		for(j=1;j<=i;j++)
	{
		cout<<"sin("<<j;
		if(j%2!=0&&j<i)
		cout<<"-";
		else if(j%2==0&&j<i)
		cout<<"+";
	}
	for(j=1;j<=i;j++)
		cout<<")";
		cout<<"+"<<x-i+1;
		if(i<x)
		cout<<")";
	}
}
