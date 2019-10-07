#include<stdio.h>
int main()
{
    int i,j,n,a[26]={0};
    scanf("%d",&n);
    char s[n];
    scanf("%s",&s);
    for(i=0;i<n;i++)
    {
        for(j=65;j<=90;j++)
        {
            if(s[i]==j||s[i]==j+32)
            a[j-65]++;
        }
    }
    for(i=0;i<26;i++)
    {
        if(a[i]==0)
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}