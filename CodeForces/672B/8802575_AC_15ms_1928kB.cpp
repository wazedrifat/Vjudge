#include<stdio.h>
int main()
{
    int n,i,j,k,a[26]={0},c=0;
    scanf("%d",&n);
    char s[n+10];
    scanf("%s",s);
    if(n>26)
        {
            printf("-1");
            return 0;
        }
    for(i=0;i<n;i++)
        a[s[i]-'a']++;
    for(i=0;i<26;i++)
    {
        if(a[i]>0)
            c=c+a[i]-1;
    }
    printf("%d",c);
    return 0;
}