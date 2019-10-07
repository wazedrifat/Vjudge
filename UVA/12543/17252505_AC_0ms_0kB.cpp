#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s, res="";

    while(cin>>s && s!="E-N-D")
	{
		int c=0;

//		cout<<endl<<endl;
//		cout<<"s="<<s<<endl;
		for(int i=0 ; i<s.length() ; i++)
		{
			int j=i, c=0;
//			cout<<"1 j="<<j<<" i="<<i<<" c="<<c<<endl;
			while(isalpha(s[i]) || s[i]=='-')
			{
				c++;
				i++;
			}
//			cout<<"2 j="<<j<<" i="<<i<<" c="<<c<<endl;
			i=j+c;

//			cout<<"3 j="<<j<<" i="<<i<<" c="<<c<<endl<<endl;;
			if(c>res.length())	res=s.substr(j, c);
		}
	}

//	if(res.length()<5)	res="E-N-D";
	for(int i=0 ; i<res.length() ; i++)
		res[i]=tolower(res[i]);

	cout<<res<<endl;
}
