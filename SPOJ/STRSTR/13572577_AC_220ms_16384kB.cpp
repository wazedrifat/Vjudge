#include<bits/stdc++.h>
using namespace std;

#define file freopen("input.txt", "r", stdin);
#define CLOCK printf("time: %lld ms\n",(long long)clock()*1000/CLOCKS_PER_SEC);

int lcp[505];
struct KMP
{
	string text;
	//for prefix of suffix of pattern
	
	int prefix(string pattern)//time : o(n)
	{
		string s=text+'$'+pattern;
//		cout<<"string="<<s<<endl;
		int i=1, j=0, cnt=0;
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
		
//		cout<<"lcp : ";
//		for(int i=0 ; i<s.length() ; i++)
//		cout<<lcp[i]<<" ";	cout<<endl;
		
		for(int i=text.length(),j=0 ; i<s.length() ; i++,j++)
		{
//			cout<<"i="<<i<<" lcp[i]="<<lcp[i]<<" j="<<j<<endl;
			if(lcp[i]!=j)	return j-1;
		}
		
		return pattern.length();
	}
	
};

int main()
{
	//file
	int test, a[105];
	cin>>test;
	
	KMP s[105];
	for(int t=1 ; t<=test ; t++)
	{
		int n;
		cin>>n;
		
		for(int i=0 ; i<n ; i++)
		cin>>s[i].text;
		
		for(int i=0 ; i<105 ; i++)	a[i]=-1;
		
		for(int i=0 ; i<n ; i++)
		{
			for(int j=0,maxi=0 ; j<n ; j++)
			{
				if(i==j)	continue;
				
//				cout<<"<<<<<<<<<< i="<<i<<" j="<<j<<">>>>>>>>>>>>>>>\n";
				int x=s[i].prefix( s[j].text );
				
//				cout<<"x="<<x<<endl<<endl;
//				cout<<"i="<<i<<" j="<<j<<" x="<<x<<endl;
				
				if(maxi<x)
				{
					maxi=x;
					a[i]=j;	
				}
			}
			if(a[ a[i] ]==-1)
			a[ a[i] ]=i;
			
//			cout<<"<<<<<<<<<<<<<<<<a["<<i<<"]="<<a[i]<<"  a["<<a[i]<<"]="<<a[ a[i] ]<<endl;
		}
		
		cout<<"Case "<<t<<": \n";
		for(int i=0 ; i<n ; i++)
		if(a[i]==-1)
		cout<<-1<<endl;
		else
		cout<<a[i]+1<<endl;
	}
//	CLOCK
}
