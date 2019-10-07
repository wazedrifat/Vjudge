#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, f[3];
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		
		f[0]=f[1]=f[2]=0;
		
		for(int i=0 ; i<s.length() ; i++)
		if(s[i]=='R')		f[0]++;
		else if(s[i]=='G')	f[1]++;
		else				f[2]++;
		
		cout<<s.length()-max(f[0], max(f[1], f[2]))<<endl;
	}
	
}
