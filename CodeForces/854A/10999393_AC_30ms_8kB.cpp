//wazed rifat
#include<bits/stdc++.h>
using namespace std;
long long int i,n;
int main()
{
	cin>>n;
	for(i=n/2;i>0;i--)
	{
		if(__gcd(i,n-i)==1)
		{
			cout<<i<<" "<<n-i;
			return 0;
		}
	}
}