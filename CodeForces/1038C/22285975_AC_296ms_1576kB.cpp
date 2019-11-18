#include<bits/stdc++.h>
using namespace std;

long long int s[2]={0, 0}, a[2][100005];
int main()
{
	int n;
	cin>>n;

	for(int i=0 ; i<n ; i++)	cin>>a[0][i];
	for(int i=0 ; i<n ; i++)	cin>>a[1][i];
	sort(a[0], a[0]+n);
	sort(a[1], a[1]+n);

	int i[2]={n-1, n-1}, f=0;
	while(i[0]>=0 || i[1]>=0)
	{
		int _f=1-f;
		if(i[_f]<0 || (i[f]>=0 && a[f][ i[f] ]>a[_f][ i[_f] ]) )	s[f]+=a[f][ i[f]-- ];
		else							i[_f]--;
		f=_f;
	}

	cout<<s[0]-s[1]<<endl;
}