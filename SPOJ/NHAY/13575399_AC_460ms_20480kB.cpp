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

void Search(string text, string pattern)//time : o(n)
{
	cnt.clear();
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
			cnt.push_back(i-j);
			j=lcp[j-1];
		}
		
		if(pattern[j]!=text[i])
			if(j)	j=lcp[j-1];
			else	i++;
	}
}

int main()
{
	int n;
	string t, p;
	
	while(scanf("%d", &n)!=EOF)
	{
		cin>>p>>t;
		
		Search(t, p);
		
		for(int i=0 ; i<cnt.size() ; i++)
		cout<<cnt[i]<<endl;
		
		cout<<endl;
	}
}
