#include<stdio.h>
int main()
{
    int t,z,x,j,y;
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        scanf("%d%d%d",&x,&y,&z);
        if(x<=20&&y<=20&&z<=20)
        printf("Case %d: good\n",j);
        else
        printf("Case %d: bad\n",j);
    }
    return 0;
}