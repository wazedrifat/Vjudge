#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, x;
	cin>>n>>x;

	int mini=x, maxi=x, cnt=0;;
	for(int i=1 ; i<n ; i++)
    {
        cin>>x;

        if(x<mini || x>maxi)  cnt++;
        mini=min(mini, x);
        maxi=max(maxi, x);
    }
    cout<<cnt;
}
