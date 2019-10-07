#include<bits/stdc++.h>
using namespace std;

#define MX 100005 //1e5+5
#define START '0'

struct Suffix
{
	int index, rank[2];
};

int SA[MX], rank[MX];
Suffix suffix[MX], res[MX];

void CountSort(int pos, int len) //time : O(n)
{
	int en=max(len, 300);
	
	int cnt[en];
	for(int i=0 ; i<en ; i++)
	cnt[i]=0;
	
	for(int i=0 ; i<len ; i++)
	cnt[ suffix[i].rank[pos]+1 ]++;
	
	int sum=0;
	for(int i=0 ; i<=en ; i++)
	{
		int prev=cnt[i];
		cnt[i]=sum;
		sum+=prev;
	}
	
	for(int i=0 ; i<len ; i++)
	res[ cnt[ suffix[i].rank[pos]+1 ]++ ]=suffix[i];
	
	for(int i=0 ; i<len ; i++)
	suffix[i]=res[i];
}

void SuffixArray(string s) //time : O(n log(n) )
{
	int len=s.length();
	
	for(int i=0 ; i<len ; i++)
	{
		suffix[i].index=i;
		suffix[i].rank[0]=s[i]-START;
		
		if(i+1<len)	suffix[i].rank[1]=s[i+1]-START;
		else		suffix[i].rank[1]=-1;
	}
	
	CountSort(1, len);	CountSort(0, len);
	
	for(int k=4 ; k<2*len ; k=k<<1)
	{
		int rnk=0;
		rank[ suffix[0].index ]=rnk;
		int prev=suffix[0].rank[0];
		suffix[0].rank[0]=rnk;
		
		for(int i=1 ; i<len ; i++)// setting value for 1st rank
		{
			if( (suffix[i].rank[0]!=prev || suffix[i].rank[1]!=suffix[i-1].rank[1]) )
			rnk++;
			
			prev=suffix[i].rank[0];
			suffix[i].rank[0]=rnk;
			rank[ suffix[i].index ]=i;
		}
		
		for(int i=0 ; i<len ; i++)// setting value for 2nd rank
		{
			int next=suffix[i].index+(k>>1);
			
			if(next<len)	suffix[i].rank[1]=suffix[ rank[next] ].rank[0];
			else			suffix[i].rank[1]=-1;
		}
		CountSort(1, len);	CountSort(0, len);
	}
	
	for(int i=0 ; i<len ; i++)	SA[i]=suffix[i].index;
	
	
    for(int i=0 ; i<len ; i++)
    rank[ suffix[i].index ]=i;
}

int lcp[MX];
long long int kasai(string s) //time : O(n log(n) )
{
	long long int cnt=0;
    int len=s.length(),k=0;

    for(int i=0; i<len ; i++, k?k--:0)
    {
        if(rank[i]==len-1)
        {
        	k=0; 
			continue;
		}
		
        int j=SA[ rank[i]+1 ];
        
		while(i+k<len && j+k<len && s[i+k]==s[j+k]) 
		k++;
        
		cnt+=k;
    }
    return cnt;
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		string s;
		cin>>s;
	
		SuffixArray(s);
		
		long long int n=s.length();
		long long int sum=(n*(n+1)/2) - kasai(s);
		
		
		cout<<sum<<endl;
//		cout<<endl;
	}
}
