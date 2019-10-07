#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,a=0;
    scanf("%d",&n);
    int s;
    for(i=0;i<n;i++)
    {
        scanf("%d",&s);
        if(s-a>=16)
        {
            printf("%d",a+15);
            goto line1;
        }
        a=s;
    }
    if(90-s>=16)
    printf("%d",a+15);
    else
    printf("90");
    line1 :
    return 0;
}