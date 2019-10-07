#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	getchar();

	while(n--)
	{
		string s;
		getline(cin, s);

		int n=s.length();

		if(n<5)
		{
			cout<<"OMG>.< I don't know!"<<endl;
			continue;
		}


		bool r=(s.substr(0, 5)=="miao."), f=(s.substr(n-5, 5)=="lala.");

		if(f==1 && r==0)
			cout<<"Freda's"<<endl;
		else if(r==1 && f==0)
			cout<<"Rainbow's" <<endl;
		else
			cout<<"OMG>.< I don't know!"<<endl;
	}
}
