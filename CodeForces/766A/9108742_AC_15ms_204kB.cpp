#include<bits/stdc++.h>
#include<string.h>
using namespace std;
long long int n,m;
char s[100005],c[100005];
int main()
{
	scanf("%s%s",&s,&c);
	n=strlen(s);
	m=strlen(c);
	if(strcmp(s,c)!=0)
	cout<<max(n,m);
	else if(strcmp(s,c)==0)
	cout<<-1;
}
