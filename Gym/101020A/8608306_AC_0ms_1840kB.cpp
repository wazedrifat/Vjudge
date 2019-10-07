#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    long long int x[n+1],y[n+1];
    for(i=1;i<=n;i++)
    scanf("%lld%lld",&x[i],&y[i]);
    for(i=1;i<=n;i++)
    printf("%lld\n",y[i]*x[i]);
    return 0;
}