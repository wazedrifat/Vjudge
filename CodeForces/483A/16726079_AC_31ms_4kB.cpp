#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int l, r;
    cin>>l>>r;

    for(long long int i=l ; i<=r ; i++)
	for(long long int j=i+1 ; j<=r ; j++)
	for(long long int k=j+1 ; k<=r ; k++)
		if(__gcd(i, j)==1 && __gcd(j, k)==1 && __gcd(i, k)!=1)
		{
			cout<<i<<" "<<j<<" "<<k;
			return 0;
		}
	cout<<-1;
}
