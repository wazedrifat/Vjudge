#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	
	int i=1, j=0, lcp[ s.length() ];
	lcp[0]=0;
	
	while( i<s.length() )
	{
		if(s[j]==s[i])
		{
			lcp[i]=++j;
			i++;
		}
		else
			if(j)	j=lcp[j-1];
			else	lcp[i++]=0;
	}
	
//	cout<<"lcp : ";
//	for(int i=0 ; i<s.length() ; i++)	cout<<lcp[i]<<" ";	cout<<endl;
	
	set<int>st;
	for(int i=1 ; i<s.length()-1 ; i++)	st.insert( lcp[i] );
	
	j=s.length()-1;
	while(j>0)
	{
//		cout<<"j="<<j<<" lcp="<<lcp[j]<<endl;
		
		if(lcp[j] && s[j]==s[ s.length()-1 ] && st.find(lcp[j])!=st.end() )
		{
			for(int i=0 ; i<lcp[j] ; i++)
			cout<<s[i];
			return 0;
		}
		else
			j=lcp[j-1];
	}
	cout<<"Just a legend\n";
}
