#include<stdio.h>
#include<string.h>
int main()
{
    char s[200];
    int i,j;
    scanf("%s",&s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='.')
        printf("0");
        else if(s[i]=='-'&&s[i+1]=='.')
        {
            printf("1");
            i++;
        }
        
        else if(s[i]=='-'&&s[i+1]=='-')
        {
            printf("2");
            i++;
        }
    }
    return 0;
}