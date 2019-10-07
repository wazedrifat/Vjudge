#include<stdio.h>
int main()
{
    int t,i,j,n,a;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a);
            if(j==(n+1)/2)
            printf("Case %d: %d\n",i+1,a);
        }
    }
    return 0;
}