//wazed rifat
#include<bits/stdc++.h>
using namespace std;
int n,m,i,a,b,arr[50000],f,l,mid,x,j;
int main()
{
	cin>>n;
	for(i=0;i<n;i++)
	cin>>arr[i];
	cin>>m;
	for(i=0,a=-1,b=-1;i<m;i++)
	{
		cin>>x;
		f=0;
		l=n-1;
		a=-1;
		b=-1;
		while(f<=l)
		{
			mid=(f+l)/2;
			if(arr[mid]==x)
			{
				for(j=mid-1;j>=0&&a<0;j--)
		      if(arr[j]<x)
				a=arr[j];
				for(j=mid+1;j<n&&b<0;j++)
				if(arr[j]>x)
				b=arr[j];
				break;
			}
			else if(arr[mid]<x)
			f=mid+1;
			else if(arr[mid]>x)
			l=mid-1;
		}
		for(j=mid+1;j>=0&&a<0;j--)
		{
			if(j<0||j>=n)
			continue;
			if(arr[j]<x)
			a=arr[j];
		}
		for(j=mid-2;j<n&&b<0;j++)
		{
			if(j<0||j>=n)
			continue;
			if(arr[j]>x)
			b=arr[j];
		}
		if(a==-1)
		cout<<"X ";
		else
		cout<<a<<" ";
		if(b==-1)
		cout<<"X"<<endl;
		else
		cout<<b<<endl;
	}
}
