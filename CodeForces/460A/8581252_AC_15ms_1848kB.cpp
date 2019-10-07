#include<stdio.h>
int main()
{
    int n,i,m,c=0;
    scanf("%d%d",&n,&m);
    for(n=n,i=1;n>0;n--,i++)
    {
        c++;
        if(i==m)
        {
            i=0;
            n++;
        }
    }
    printf("%d",c);
    return 0;
}