//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define LLI long long int

LLI n,t,cnt,i,j;

int main(	)
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//	freopen("input1.txt","r",stdin);
	
	cin>>t;
	
	while(t--)
	{
		cin>>i>>j;
		
		cout<<max(i,j)<<" "<<i+j<<endl;
	}
	
}