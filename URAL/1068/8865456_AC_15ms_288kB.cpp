#include<stdio.h>
int main()
{
	long long int n,i,s=0;
	scanf("%lld",&n);
	if(n<1)
    for(i=n;i<=1;i++)
    s=s+i;
    else 
    for(i=1;i<=n;i++)
    s=s+i;
    printf("%lld",s);
}
