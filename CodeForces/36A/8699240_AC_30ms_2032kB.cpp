#include<stdio.h>
int main()
{
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout);
	int n,i,a=-1,b=-1,c,d;
	scanf("%d",&n);
	char s[n];
	scanf("%s",&s);
	for(i=0;i<n;i++)
	{
		if(s[i]=='1'&&a<0)
		{
			a=i;
			continue;
		}
		if(s[i]=='1')
		{
			b=i;
			break;
		}
	}
	
	c=b;
	for(i=b+1;i<n;i++)
	{
		if(s[i]=='1')
		{
			d=i;
			if(d-c!=b-a)
			{
				printf("NO");
				return 0;
			}
			c=i;
		}
	}
	printf("YES");
	return 0;
}