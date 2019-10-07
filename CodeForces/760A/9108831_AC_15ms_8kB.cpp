#include<bits/stdc++.h>
using namespace std;
int a,b,d,m;
int main()
{
	cin>>m>>d;
	if(m==2)
	a=28;
	else if(m==4||m==6||m==9||m==11)
	a=30;
	else
	a=31;
	a+=d-1;
	b=a/7;
	if(a%7!=0)
	b++;
	cout<<b;
}
