#include<stdio.h>
int main()
{
    int n,m,a,b,c,d;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    if(m*a<=b)
    printf("%d",n*a);
    else
    {
        c=(n/m)*b;
        d=(n%m)*a;
        if(d<=b)
        printf("%d",c+d);
        else
        printf("%d",c+b);
    }
    return 0;
}