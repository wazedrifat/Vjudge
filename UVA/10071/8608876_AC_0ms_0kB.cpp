#include<stdio.h>
int main()
{
    long long int i,v,t;
    for(i=0;scanf("%lld%lld",&v,&t)!=EOF;i++)
    printf("%lld\n",2*v*t);
    return 0;
}