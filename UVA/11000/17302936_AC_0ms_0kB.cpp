#include<bits/stdc++.h>
using namespace std;

#define MX 100000

long long int n, male[MX], female[MX];

int main()
{
	while(cin>>n && n!=-1)
	{
		male[0]=0; female[0]=1;
		for(int i=1 ; i<=n ; i++)
		{
			female[i]=male[i-1]+1;
			male[i]=female[i-1]+male[i-1];
		}
		cout<<male[n]<<" "<<male[n]+female[n]<<endl;
	}
}
