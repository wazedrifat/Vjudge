#include<bits/stdc++.h>
using namespace std;

#define file freopen("input.txt", "r", stdin);
#define CLOCK printf("time: %lld ms\n",(long long)clock()*1000/CLOCKS_PER_SEC);

int lcp[300005];
int prefix(string text)//time : o(n)
{
	string s="$";
	s+=text;
//	cout<<"string="<<s<<" text="<<text<<endl;
	reverse(s.begin(), s.end());
//	cout<<"string="<<s<<" text="<<text<<endl;
	s+=text;
	
//	cout<<"string="<<s<<" text="<<text<<endl;
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
	
	j=lcp[ s.length()-1 ];
	for(int i=s.length(),cnt=0 ; i>=0 ; cnt++,i--,j--)
	{
//		cout<<"i="<<i<<" lcp[i]="<<lcp[i]<<" j="<<j<<endl;
		if(lcp[i]!=j)	return text.length()-lcp[ s.length()-1 ];
	}
	
	return text.length();
}

int main()
{
	//file
	int test;
	cin>>test;
	
	string s;
	char ch[200005];
	while(scanf("%s", &ch)!=EOF)
	{
		s=ch;
//		cout<<"input="<<s<<endl;
		int m=prefix(s);
		
//		cout<<"m="<<m<<endl;
		cout<<s;
		
		for(int i=m-1 ; i>=0 ; i--)
		cout<<s[i];
		cout<<endl;
	}
//	CLOCK
}
