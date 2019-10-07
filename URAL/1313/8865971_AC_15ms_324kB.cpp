#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i=0,j=0,k=0,l=0,a[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		scanf("%d",&a[j][i]);
	}
	while(k<n&&l<n)
	{
		for(i=l,j=k;i<n&&j>=0;i++,j--)
		printf("%d\n",a[i][j]);
		if(k<n-1)
		k++;
		else
		l++;
	}
}