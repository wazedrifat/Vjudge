#include<stdio.h>
#include<string.h>
int main()
{
	int i,j;
    char s[210],c[210]={'\0'};
    scanf("%s",&s);
    for(i=0,j=0;i<strlen(s);i++)
    {
        if(s[i]=='W'&&s[i+1]=='U'&&s[i+2]=='B')
        {
            c[j]=' ';
            j++;
            i=i+2;
        }
        else
        {
            c[j]=s[i];
            j++;
        }
    }
    printf("%s",c);
    return 0;
}