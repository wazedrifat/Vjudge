#include<stdio.h>
int main()
{
	int n,i,j,s=0,a,b;
	scanf("%d",&n);
	int d[n];
	d[0]=0;
	for(i=1;i<n;i++)
	scanf("%d",&d[i]);
	scanf("%d%d",&a,&b);
	for(j=a;j<b;j++)
	{
		s=s+d[j];
	}
	printf("%d",s);
}