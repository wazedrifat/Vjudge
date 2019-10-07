#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    scanf("%s",&s);
    int i,j,k,l,m,n;
    n=strlen(s);
    for(i=0;i<n;i++)
    {
    if(s[i]=='h')
    {
    for(i=i+1;i<n;i++)
    {
    if(s[i]=='e')
    {
    for(i=i+1;i<n;i++)
    {
    if(s[i]=='l')
    {
    for(i=i+1;i<n;i++)
    {
    if(s[i]=='l')
    {
    for(i=i+1;i<n;i++)
    {
    if(s[i]=='o') {      
                                        printf("YES");   goto line1;                        }
    }
    }  
    }           
    }
    }
    }
    }
    }
        
    }
    printf("NO");
    line1 :
    return 0;
}