#include<bits/stdc++.h>
#include<vector>
#include<stdbool.h>
using namespace std;
vector<int>a;
long long int x,t,i=0,j=0,k;
int main()
{
	cin>>t;
	for(k=1;k<=t;k++)
	{
		cin>>x;
		x--;
        while(i<=x+1)
	    {
		    a.push_back(i);
		    j++;
		    i+=j;
	    }
		if(binary_search(a.begin(),a.end(),x))
            cout<<"1 ";
        else
	        cout<<"0 ";
	}
}