//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define LLI long long int

LLI cnt,cnt1,i,len;
string s;
char ch;

int main(	)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

//	freopen("input1.txt","r",stdin);
	
	cin>>s;
	
	len=s.length();
	
	for(i=0,cnt1=0 ; i<len ; i++)
	{
		cnt=0;
		ch=s[i];
		
		for(cnt=1 ; i<len&&s[i+1]==ch ; i++)
		cnt++;
		
		if(cnt%2==0)
		cnt1++;
	}
	
	cout<<cnt1;
	
}

