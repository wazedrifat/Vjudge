#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,a=0,b=0;
	char s[100000];
	scanf("%s",&s);
	for(i=0,j=0;i<strlen(s);i++,j++)
	{
		if(s[i]=='A'&&s[i+1]=='B'&&a==0)
		{
			a=1;
			i++;
		}
		else if(s[i]=='B'&&s[i+1]=='A'&&a==1)
		{
			printf("YES");
			return 0;
		}
		if(s[j]=='B'&&s[j+1]=='A'&&b==0)
		{
			b=1;
			j++;
		}
		else if(s[j]=='A'&&s[j+1]=='B'&&b==1)
		{
			printf("YES");
			return 0;
		}
	}
	printf("NO");
	return 0;
}