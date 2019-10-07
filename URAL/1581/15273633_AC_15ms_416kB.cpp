#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("output.txt", "w", stdout);
	int n;
	cin>>n;

	int cur, prev, cnt=1;
	cin>>prev;

	for(int i=1 ; i<n ; i++)
	{
		cin>>cur;
		if(cur!=prev)
		{
			cout<<cnt<<" "<<prev<<" ";
			cnt=1;
		}
		else	cnt++;
		prev=cur;
	}
	cout<<cnt<<" "<<prev<<endl;
	return 0;
}
