#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    long long int i,j,k,n,c=0,t=1;
    char s[50];
	gets(s);
	n=atoi(s);
	long long int a=strlen(s);
	for(i=1,c=0;i<a;i++)
	{
		if(s[i]=='!')
		c++;
	}
	for(i=0,t=1;n-i*c>0;i++)
	t=t*(n-i*c);
	printf("%lld",t);
}