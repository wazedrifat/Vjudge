//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define LLI long long int

int n,t,cnt;

int main(	)
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//	freopen("input1.txt","r",stdin);
	
	cin>>t;
	
	while(t--)
	{
		cnt=0;
		cin>>n;
		
		while(n)
		{
			if(n%10==4)
			cnt++;
			
			n/=10;
		}
		
		cout<<cnt;
		
//		if(t)
		cout<<endl;
	}
	
}