#include<stdio.h>
int main()
{
    int n,a,b,c=0,i;
    scanf("%d%d%d",&n,&a,&b);
    for(i=a+1;i<=n;i++)
    {
        if(n-i<=b)
        c++;
    }
    printf("%d",c);
    return 0;
}