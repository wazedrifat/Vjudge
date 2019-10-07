#include<bits/stdc++.h>
using namespace std;

#define MX 100000 //1e6+5

bool flag[MX];
vector<int>prime;

void SieveOfEratosthenes(int limit=MX)
{
	flag[0]=flag[1]=1;

	for(int i=4 ; i<=limit ; i+=2)
	flag[i]=1;

	for(int i=3 ; i*i<limit ; i+=2)
	if(flag[i]==0)
		for(int j=i*i ; j<=limit ; j+=2*i)	flag[j]=1;

}

int main()
{
	SieveOfEratosthenes();
	string s;
	while(cin>>s && s!="0")
	{
		int maxi=-1;
		for(int len=6 ; len>0 ; len--)
		{
//			if(s.length()<len)	continue;
//			cout<<"len="<<len<<endl;
			for(int i=0 ; i+len-1<s.length() ; i++)
			{
				stringstream ss(s.substr(i, len));
				int x=0;
				ss>>x;

//				cout<<x;
//				if(x<=MX && !flag[x])	cout<<"(prime)";
//				cout<<endl;
				if(x<=MX && !flag[x] && x>maxi)
					maxi=x;
			}
//			cout<<endl;
		}
		cout<<maxi<<endl;

	}
}
