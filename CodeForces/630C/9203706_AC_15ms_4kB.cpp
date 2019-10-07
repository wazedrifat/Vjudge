#include<bits/stdc++.h>
using namespace std;
long long int n,s=0;
int main()
{
	cin>>n;
	while(n--)
	s+=pow(2,n+1);
	cout<<s;
}
