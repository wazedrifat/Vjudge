#include<stdio.h>
int main()
{
    int t,i,l=0,x,j,y;
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        l=0;
        scanf("%d",&y);
        for(i=0;i<y;i++)
    {
        scanf("%d",&x);
        if(x>=l)
        l=x;
    }
        printf("Case %d: %d\n",j,l);
    }
    return 0;
}