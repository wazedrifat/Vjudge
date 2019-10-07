#include<stdio.h>
#include<string.h>
int main()
{
    int i,j=0;
    char s[50],c[50],ch[50];
    scanf("%s",&s);
    if(s[0]=='f')
    {
        c[j]=s[3];
        j++;
    }
    for(i=4;j==0||(s[i]!='r'||s[i+1]!='u');i++)
    {
        
           c[j]=s[i];
           j++;
    }
    c[j]='\0';
    for(i=i+2,j=0;i<strlen(s);i++)
    {
        ch[j]=s[i];
        j++;
    }
    ch[j]='\0';
    if(s[0]=='h'&&j!=0)
    printf("http://%s.ru/%s",c,ch);
    else if(s[0]=='f'&&j!=0)
    printf("ftp://%s.ru/%s",c,ch);
    else if(s[0]=='h'&&j==0)
    printf("http://%s.ru",c);
    else if(s[0]=='f'&&j==0)
    printf("ftp://%s.ru",c);
    return 0;
}