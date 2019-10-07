#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,a=0,b=0,c=0;
    char s[100];
    scanf("%s",&s);
    n=strlen(s);
    for(i=0;i<n;i++)
    {
        if(s[i]=='1')
        a++;
        else if(s[i]=='2')
        b++;
        else if(s[i]=='3')
        c++;
    }
    for(i=0;i<a;i++)
    {
        if(b==0&&c==0)
        {
            printf("1");
            if(i<a-1)
            printf("+");
        }
        else
        printf("1+");
    }
    for(i=0;i<b;i++)
    {
        if(c!=0)
        printf("2+");
        else if(c==0)
        {
            printf("2");
            if(i<b-1)
            printf("+");
        }
    }
    for(i=0;i<c;i++)
    {
        printf("3");
        if(i<c-1)
        printf("+");
    }
    return 0;
}