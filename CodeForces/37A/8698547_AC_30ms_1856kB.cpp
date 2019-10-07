#include<stdio.h>
int main()
{
	int n,i,j,k=0,f,d=0,e=0;
	scanf("%d",&n);
	int l[n],c[n]={0};
	for(i=0;i<n;i++)
	scanf("%d",&l[i]);
	for(i=0;i<n;i++)
	{
		c[i]=1;
		for(j=i+1;j<n;j++)
		{
			if(l[i]==NULL)
			continue;
			if(l[i]==l[j])
			{
				l[j]=NULL;
				c[i]++;
			}
		}
		if(c[i]!=0&&l[i]!=NULL)
		d++;
		else if(c[i]==0&&l[i]!=NULL)
		{
			e++;
			c[i]=1;
		}	
	}
	f=c[0];
	for(i=0;i<n;i++)
	{
		if(c[i]>f)
		f=c[i];
	}
	printf("%d %d",f,d+e);
}