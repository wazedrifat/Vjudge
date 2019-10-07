//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define LLI long long int

LLI i,j,n,test,sum,ans,cnt,t,k;

int main(	)
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//	freopen("input1.txt","r",stdin);
	
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		
		sum=n%10;
		
		while(n)
		{
			k=n%10;
			n/=10;
		}
		
		cout<<sum+k<<endl;
	}
	
}

