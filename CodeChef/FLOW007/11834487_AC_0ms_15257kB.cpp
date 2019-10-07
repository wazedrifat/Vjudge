//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define LLI long long int

int n,t,f=0;

int main(	)
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//	freopen("input1.txt","r",stdin);
	
	cin>>t;
	
	while(t--)
	{
		f=0;
		cin>>n;
		
		while(n)
		{
			if(n%10!=0)
			f=1;
			
			if(f==1)
			cout<<n%10;
			
			n/=10;
		}
		
		cout<<endl;
	}
	
}