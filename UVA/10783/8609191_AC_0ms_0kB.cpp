#include<stdio.h>
int main()
{
    int i,j,t;
    scanf("%d",&t);
    int x[t+1],y[t+1],s[t+1];
    for(i=1;i<=t;i++)
    {
        s[i]=0;
        scanf("%d%d",&x[i],&y[i]);
        for(j=x[i];j<=y[i];j++)
        {
            if(j%2!=0)
            s[i]=s[i]+j;
        }
    }
    for(i=1;i<=t;i++)
    printf("Case %d: %d\n",i,s[i]);
    return 0;
}