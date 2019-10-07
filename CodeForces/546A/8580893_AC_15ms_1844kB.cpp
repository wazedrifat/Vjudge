#include<stdio.h>
int main()
{
	int k,n,w,i,s=0,c;
	scanf("%d%d%d",&k,&n,&w);
	for(i=1;i<=w;i++)
	s=s+i*k;
	if(s>=n)
	c=s-n;
	else if(s<n)
	c=0;
	printf("%d",c);
	return 0;
}