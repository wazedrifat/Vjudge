#include<bits/stdc++.h>
using namespace std;

#define PII pair<int, int>

bool cmp(PII a, PII b)
{
	return a.first<=b.first;
}

int main()
{
	int n;
	cin>>n;

	PII p[150005];

	for(int i=0 ; i<n ; i++)
		cin>>p[i].second>>p[i].first;

	stable_sort(p, p+n, cmp);

	for(int i=n-1 ; i>=0 ; i--)
		cout<<p[i].second<<" "<<p[i].first<<endl;
}
