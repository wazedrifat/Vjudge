#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,l,n=1;
    char ch[100];
    scanf("%s",&ch);
    l=strlen(ch);
    for(i=0;i<l;i++)
    {
        if(ch[i]==ch[i+1])
        {
            n++;
            if(n>=7)
            {
                printf("YES");
                exit(0);
            }
            
        }
        else if(ch[i]!=ch[i+1])
        n=1;
    }
    printf("NO");
    return 0;
}