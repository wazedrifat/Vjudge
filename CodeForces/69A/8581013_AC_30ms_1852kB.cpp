#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    int x[n],y[n],z[n],a=0,b=0,c=0;
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&x[i],&y[i],&z[i]);
        a=a+x[i];
        b=b+y[i];
        c=c+z[i];
    }
    if(a==0&&b==0&&c==0)
    printf("YES");
    else
    printf("NO");
    return 0;
}