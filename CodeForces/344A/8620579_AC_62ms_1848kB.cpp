#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,d=0;
    scanf("%d",&n);
    char s[3],c[3];
    scanf("%s",&s);
    for(i=1;i<n;i++)
    {
        scanf("%s",&c);
        if(strcmp(s,c)==0)
        d++;
        strcpy(s,c);
    }
    printf("%d",n-d);
    return 0;
}