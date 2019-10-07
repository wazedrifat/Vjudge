#include<stdio.h>
#include<string.h>
int main()
{
	int i,c=0;
	char s[100];
	scanf("%s",&s);
	for(i=0;i<strlen(s);i=i+3)
	{
		if(s[i]!='S')
		c++;
		if(s[i+1]!='O')
		c++;
		if(s[i+2]!='S')
		c++;
	}
	printf("%d",c);
}