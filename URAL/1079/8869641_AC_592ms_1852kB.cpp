#include<stdio.h>
long long int a[100001],l[100001];
int value(int p)
{
	if(p==0)
	return 0;
	else if(p==1)
	return 1;
	if(p%2==0)
	a[p]=value(p/2);
	else if(p%2!=0)
	a[p]=value(p/2)+value(p/2+1);
	return a[p];
}
int main()
{
	long long int n,i;
	for(i=0;i<=100000;i++)
	{
		a[i]=value(i);
		if(l[i]<a[i])
		l[i]=a[i];
		l[i+1]=l[i];
	}
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)
		return 0;
		printf("%lld\n",l[n]);
	}
	return 0;
}