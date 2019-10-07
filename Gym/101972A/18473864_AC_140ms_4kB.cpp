#include<bits/stdc++.h>
using namespace std;

vector<int>x, y;

void analyze(int a, vector<int>&v)
{
	int c=1;
	while(a)
	{
        int m=a%10;
        a/=10;

        if(m)
        v.push_back(m*c);
		c*=10;
	}

}

void print(vector<int>&v)
{
	for(auto i : v)
		cout<<i<<" ";
	cout<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
        int a, b;
        cin>>a>>b;

        x.clear();
        y.clear();
        analyze(a, x);
//        print(x);
        analyze(b, y);
//        print(y);

        for(int i=0 ; i<x.size() ; i++)
		for(int j=0 ; j<y.size() ; j++)
		{
			cout<<x[i]<<" x "<<y[j];

			if( !(i==x.size()-1 && j==y.size()-1) )
				cout<<" + ";
			else
				cout<<endl;
		}

	}

}
