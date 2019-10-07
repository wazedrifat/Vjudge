#include<bits/stdc++.h>
using namespace std;
long long int n,s=0,i,a[10001],x;
int main()
{
	while(1)
	{
		cin>>x;
		if(x<0)
		break;
   	for(i=0,s=0;i<x;i++)
   	{
   		cin>>a[i];
   		s+=a[i];
   	}
   	if(s%x!=0)
   	{
   		cout<<-1<<endl;
   		continue;
   	}
   	else
   	{
   		n=s/x;
   		for(i=0,s=0;i<x;i++)
   		if(n>a[i])
   		s+=n-a[i];
   	}
   	cout<<s<<endl;
	}
}
