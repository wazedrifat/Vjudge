#include<bits/stdc++.h>
#include<vector>
#include<stdlib.h>
using namespace std;
vector<long long int>a;
long long int c,n,l,x,i;
int main()
{
	cin>>n>>l;
	for(i=0;i<n;i++)
	{
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	c=max(a[0],l-a[n-1])*2;
	for(i=1;i<n;i++)
	c=max(c,a[i]-a[i-1]);
	printf("%lf",(double)c/2);
}