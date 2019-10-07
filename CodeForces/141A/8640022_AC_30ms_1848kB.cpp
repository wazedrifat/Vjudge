#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,a[26]={0},b[26]={0};
    char s1[100],s2[100],ch[100];
    scanf("%s%s%s",&s1,&s2,&ch);
    for(i=0;i<strlen(ch);i++)
    {
        if(i<strlen(s1))
        a[s1[i]-65]++;
        if(i<strlen(s2))
        a[s2[i]-65]++;
        b[ch[i]-65]++;
    }
    for(i=0;i<26;i++)
    {
        if(a[i]!=b[i])
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}