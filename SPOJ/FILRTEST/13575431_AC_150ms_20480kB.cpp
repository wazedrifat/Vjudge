#include<bits/stdc++.h>
using namespace std;

#define file freopen("input.txt", "r", stdin);
#define CLOCK printf("time: %lld ms\n",(long long)clock()*1000/CLOCKS_PER_SEC);

int lcp[1000005];//for prefix of suffix of pattern
vector<int>cnt;

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

int main()
{
	int n;		string s;
	while(cin>>n>>s && n!=-1)
	{
		lcp_array(s);
		
		int x=lcp[ s.length()-1 ];
		
		if(n<s.length())	cout<<0<<endl;
		else
		cout<<(n-x)/(s.length()-x)<<endl;
	}
}
