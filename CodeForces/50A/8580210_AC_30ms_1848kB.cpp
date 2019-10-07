#include<stdio.h>
int main()
{
    int m,n,s;
    scanf("%d%d",&m,&n);
    if(m%2==0&&n%2==0)
    s=(m/2)*n;
    else if(m%2==0&n%2!=0)
    s=(m/2)*n;
    else if(n%2==0&&m%2!=0)
    s=(n/2)*m;
    else if(m%2!=0&&n%2!=0)
    s=(m/2)*n+(n/2);
    printf("%d",s);
    return 0;
}