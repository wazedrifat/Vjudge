#include<stdio.h>
int main()
{
    int x,j,y=0;
    for(j=1;j<=5;j++)
    {
        scanf("%d",&x);
        y=y+x;
    }
    if(y%5==0&&y/5!=0)
    printf("%d",y/5);
    else
    printf("-1");
    return 0;
}