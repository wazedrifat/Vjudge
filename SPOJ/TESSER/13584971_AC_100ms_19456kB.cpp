#include<bits/stdc++.h>
using namespace std;

#define file freopen("input.txt", "r", stdin);
#define CLOCK printf("time: %lld ms\n",(long long)clock()*1000/CLOCKS_PER_SEC);

int lcp[1000005];//for prefix of suffix of pattern

void lcp_array(string pattern)//time : o(n)
{
	int i=1, j=0;
	lcp[0]=0;
	
	while( i<pattern.length() )
	{
		if(pattern[j]==pattern[i])
		{
			lcp[i]=++j;
			i++;
		}
		else
			if(j)	j=lcp[j-1];
			else	lcp[i++]=0;
	}
}

bool Search(string text, string pattern)//time : o(n)
{
	lcp_array(pattern);
	
	int i=0, j=0;//i for text & j for pattern
	while( i<text.length() )
	{
		if(pattern[j]==text[i])
		{
			i++;	j++;
		}
		
		if(j==pattern.length())
		{
//			cout<<"j="<<j<<endl;
			return 1;
			j=lcp[j-1];
		}
		
		if(pattern[j]!=text[i])
			if(j)	j=lcp[j-1];
			else	i++;
	}
	
	return 0;
}

int main()
{
//	file
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int a, b;
		string s;
		
		cin>>a;
		for(int i=0 ; i<n-1 ; i++)
		{
			cin>>b;
			
			if(b>a)			s+='G';
			else if(b==a)	s+='E';
			else			s+='L';
			
			a=b;
		}
		
		string p;
		cin>>p;
		
//		cout<<"s="<<s<<"  p="<<p<<endl;
		if( Search(s, p) )
		cout<<"YES\n";
		else
		cout<<"NO\n";
		
	}
}
