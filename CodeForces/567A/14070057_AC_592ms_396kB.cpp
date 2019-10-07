#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, a[100005];
	cin>>n;

	for(int i=0 ; i<n ; i++)
        cin>>a[i];

    for(int i=0 ; i<n ; i++)
    {
        int m1=INT_MAX;

        if(i)   m1=a[i]-a[i-1];
        if(i<n-1)   m1=min(m1, a[i+1]-a[i]);

        cout<<m1<<" "<<max(a[n-1]-a[i], a[i]-a[0])<<endl;
    }
}
