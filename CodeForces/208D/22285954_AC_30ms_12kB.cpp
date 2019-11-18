#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll n, freq[5], a[5], p[100];

int main()
{
    cin>>n;

    for(int i=0 ; i<n ; i++)
		cin>>p[i];

	for(int i=0 ; i<5 ; i++)
		cin>>a[i];

	ll sum=0;
	for(int i=0 ; i<n ; i++)
	{
		sum+=p[i];

		for(int i=4 ; i>=0 ; i--)
            if(sum>=a[i])
			{
				freq[i]+=sum/a[i];
				sum%=a[i];
//				cout<<"i="<<i<<" sum="<<sum<<endl;
			}
	}

	for(int i=0 ; i<5 ; i++)
		cout<<freq[i]<<" ";
	cout<<endl<<sum;
}