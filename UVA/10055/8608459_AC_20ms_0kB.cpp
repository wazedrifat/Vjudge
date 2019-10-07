#include<stdio.h>
int main()
{
    long long int i,x,y;
    
    for(i=0;scanf("%lld%lld",&x,&y)!=EOF;i++)
    {
        if(x>=y)
        printf("%lld\n",x-y);
        else
        printf("%lld\n",y-x);
    }
    return 0;
}