#include<stdio.h>
#include<string.h>
int main()
{
	int i,n;
	scanf("%d",&n);
	char s[n][20],c[n][20];
	for(i=0;i<n;i++)
	{
		scanf("%s %s",s[i],c[i]);
	}
	for(i=0;i<n;i++)
	if(strcmp(c[i],"rat")==0)
	printf("%s\n",s[i]);
	for(i=0;i<n;i++)
	if(strcmp(c[i],"woman")==0||strcmp(c[i],"child")==0)
	printf("%s\n",s[i]);
	for(i=0;i<n;i++)
	if(strcmp(c[i],"man")==0)
	printf("%s\n",s[i]);
	for(i=0;i<n;i++)
	if(strcmp(c[i],"captain")==0)
	printf("%s\n",s[i]);
}