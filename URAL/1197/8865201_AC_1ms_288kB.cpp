#include<stdio.h>
int main()
{
	int i,j,k,n,t;
	char s[3];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		n=0;
		scanf("%s",s);
		if(s[0]+2<=104&&s[0]+2>=97&&s[1]+1>=49&&s[1]+1<=56)
		n++;
		if(s[0]-2<=104&&s[0]-2>=97&&s[1]-1>=49&&s[1]-1<=56)
		n++;
		if(s[0]+2<=104&&s[0]+2>=97&&s[1]-1>=49&&s[1]-1<=56)
		n++;
		if(s[0]-2<=104&&s[0]-2>=97&&s[1]+1>=49&&s[1]+1<=56)
		n++;
		if(s[0]+1<=104&&s[0]+1>=97&&s[1]+2>=49&&s[1]+2<=56)
		n++;
		if(s[0]-1<=104&&s[0]-1>=97&&s[1]-2>=49&&s[1]-2<=56)
		n++;
		if(s[0]+1<=104&&s[0]+1>=97&&s[1]-2>=49&&s[1]-2<=56)
		n++;
		if(s[0]-1<=104&&s[0]-1>=97&&s[1]+2>=49&&s[1]+2<=56)
		n++;
		printf("%d\n",n);
	}
}