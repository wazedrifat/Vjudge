//wazed rifat
#include<bits/stdc++.h>
using namespace std;
int i,j,n,k,a[1000],b[1000],f=0,s=0,m,result;
int main()
{
	cin>>n>>k;
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0,m=9999;i<n;i++)
	{
		cin>>b[i];
		if(b[i]/a[i]<m)
		m=b[i]/a[i];
	}
	result=m;
	for(i=0;i<n;i++)
	b[i]-=m*a[i];
	///cout<<result<<endl;
	while(k>0)
	{
		for(i=0,s=0;i<n;i++)
		if(a[i]>=b[i])
		{
			s+=a[i]-b[i];
			b[i]=0;
			f=1;
		}
		else
		b[i]-=a[i];
		if(k>=s)
		result++;
		k-=s;
		//cout<<s<<"	"<<k<<endl;
	}
	cout<<result;
}
