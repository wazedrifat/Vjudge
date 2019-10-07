#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i=0,j=0,k=n-1,l=0,c=1,a[n][n];
	while(k<n&&l<n)
	{
		for(i=l,j=k;i<n&&j<n;i++,j++)
		{
			a[i][j]=c;
			c++;
		}
		if(k>0)
		k--;
		else
		l++;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		printf("%d ",a[i][j]);
		printf("\n");
	}
}