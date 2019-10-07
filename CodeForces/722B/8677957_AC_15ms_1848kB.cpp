#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,j,d=0;
    scanf("%d",&t);
    int n[t+2],c[t+2];
    char s[100];
    for(i=1;i<=t;i++)
    scanf("%d",&n[i]);
    for(i=0;i<=t;i++)
    {
        c[i]=0;
        gets(s);
        for(j=0;j<strlen(s);j++)
        {
            
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'||s[j]=='y')
            c[i]++;
        }
        if(c[i]==n[i])
        d++;
    }
    if(d==t)
    printf("YES");
    else 
    printf("NO");
    return 0;
}