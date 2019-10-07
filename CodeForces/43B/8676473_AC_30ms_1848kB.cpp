#include<stdio.h>
#include<string.h>
int main()
{
    char s1[200],s2[200];
    int a[60]={0},b[60]={0},i,j;
    gets(s1);
    gets(s2);
    for(i=0;i<strlen(s1);i++)
    {
        if(s1[i]!=' ')
        a[s1[i]-65]++;
        if(i<strlen(s2)&&s2[i]!=' ')
        b[s2[i]-65]++;
    }
    for(i=0;i<60;i++)
    {
        if(a[i]<b[i])
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}