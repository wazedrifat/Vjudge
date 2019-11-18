#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long int

int main()
{
	string s;
	cin>>s;

	ll i=0, sum=1, n=s.length();

	while(i<n)
	{
		ll j=i, cnt=1;
		while(j<n && s[j]!='b')
			cnt+=(s[j++]=='a');
		i=j+1;

		sum=(sum*cnt)%MOD;

//		cout<<"i="<<j<<" cnt="<<cnt<<" sum="<<sum<<endl;
	}

	sum--;
	if(sum<0)	sum+=MOD;
	cout<<sum;
}