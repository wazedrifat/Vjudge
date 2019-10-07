#include<stdio.h>
#include<string.h>
int main()
{
    char c[1000];
    scanf("%s",&c);
    if(c[0]>96&&c[0]<123)
        c[0]=c[0]-32;
    printf("%s",c);
    return 0;
}