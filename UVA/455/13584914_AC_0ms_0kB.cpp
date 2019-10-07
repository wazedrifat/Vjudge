#include<bits/stdc++.h>
using namespace std;

#define file freopen("input.txt", "r", stdin);
#define CLOCK printf("time: %lld ms\n",(long long)clock()*1000/CLOCKS_PER_SEC);

int lcp[1000005];//for prefix of suffix of pattern
vector<int>cnt;

int power(string pattern)//time : o(n)
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
	
	int x=pattern.length();
	int y=( pattern.length() - lcp[ pattern.length()-1 ] );
	
	if(x%y)
	return x;
	else
	return y;
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		string s;
		cin>>s;
		cout<<power(s)<<endl;
		
		if(t)	cout<<endl;
	}
}
