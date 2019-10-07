//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define LLI long long int

int t,i,sum,l;
string s;

int main(	)
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//	freopen("input1.txt","r",stdin);
	
	cin>>t;
	
	while(t--)
	{
		cin>>s;
		
		l=s.length();
		
		for(i=0,sum=0 ; i<l ; i++)
		sum+=s[i]-'0';
		
		cout<<sum<<endl;
	}

}

