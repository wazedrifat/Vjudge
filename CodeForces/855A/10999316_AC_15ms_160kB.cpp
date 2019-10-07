//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define LLI long long int
#define LI long int
#define I int
#define D double
#define MAX(A,B,C) max(a,max(b,c))
#define MIN(A,B,C) min(a,min(b,c))

LLI i,j,n,test;
string s;
map<string,bool>m;

int main(	)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

//	freopen("input1.txt","r",stdin);

//	cin>>test;

//	while(test--)
//	{
	cin>>n;
	
	for(i=0 ; i<n ; i++)
	{
		cin>>s;
		
		if(m[s])
		cout<<"YES"<<endl;
		else
		{
			m[s]=1;
			
			cout<<"NO"<<endl;
		}
		
	}
	
//	cout<<endl<<endl;
//	}
}

