#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int a,c=0,i;
    char n[3];
    scanf("%s",&n);
    for(i=1;i<=3;i++)
    {
        if(n[i]=='4'||n[i]=='7')
        c++;
    }
    if(c==strlen(n))
    printf("YES");
    else
    {
        a=atoi(n);
        if(a%4==0||a%7==0||a%44==0||a%47==0||a%74==0||a%77==0||a%444==0||a%447==0||a%474==0||a%477==0)
        printf("YES");
        else 
        printf("NO");
    }
    return 0;
}