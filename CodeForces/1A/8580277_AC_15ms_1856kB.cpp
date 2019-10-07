#include<stdio.h>
#include<math.h>
int main()
{
    unsigned long long int n,m,a;
    unsigned long long int p,q,r,s,t;
    scanf("%llu%llu%llu",&n,&m,&a);
    if(n%a==0)
    p=n/a;
    else
    p=(n/a)+1;
    if(m%a==0)
    q=m/a;
    else
    q=m/a+1;
    printf("%llu",p*q);
    return 0;
}