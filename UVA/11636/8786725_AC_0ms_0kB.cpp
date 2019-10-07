#include<stdio.h>
int main()
{
    int i,j,n,s;
    for(i=1;;i++)
    {
        scanf("%d",&n);
        if(n<0)
            break;
        for(j=0,s=1;s<n;j++)
        {
            s=s*2;
        }
        printf("Case %d: %d\n",i,j);
    }
}
