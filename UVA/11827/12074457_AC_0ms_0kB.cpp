//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define LLI long long int
#define PI 2.0*acos(0.0)
#define PII pair<int,int>
#define READ freopen("input1.txt","r",stdin);
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int i,j,n,m,maxx,test,sum,cnt,t,ps,l;
string s;
vector<int>v;

int main(	)
{
	cin>>n;
	getchar();
	
	while(n--)
	{
		getline(cin,s);
		
		for(i=0,l=s.length(),sum=0 ; i<l ; i++)
		{
			if(s[i]==' ')
			{
				if(sum)
				v.push_back(sum);
				sum=0;
				continue;
			}
			
			sum=sum*10+s[i]-'0';
		}
		
		if(sum)
		v.push_back(sum);
		
//		for(i=0 ; i<v.size() ; i++)
//		cout<<v[i]<<" ";
//		cout<<endl;
		
		for(i=0,l=v.size(),maxx=0 ; i<l ; i++)
		for(j=i+1 ; j<l ; j++)
		{
			m=__gcd(v[i],v[j]);
			
//			cout<<m<<endl;
			
			if(m>maxx)	maxx=m;
		}
		
		v.clear();
		
		cout<<maxx<<endl;
	}
	
}

