#include<bits/stdc++.h>
using namespace std;

struct person
{
	string name;
	int d, m, y;
};

bool cmp(person a, person b)
{
	if(a.y<b.y)			return 1;
	else if(a.y>b.y)	return 0;
	else
		if(a.m<b.m)			return 1;
		else if(a.m>b.m)	return 0;
		else
			return a.d<b.d;
}
int main()
{
	int n;
	cin>>n;

	person p[200];
	for(int i=0 ; i<n ; i++)
		cin>>p[i].name>>p[i].d>>p[i].m>>p[i].y;

	sort(p, p+n, cmp);

	cout<<p[n-1].name<<endl<<p[0].name<<endl;
}
