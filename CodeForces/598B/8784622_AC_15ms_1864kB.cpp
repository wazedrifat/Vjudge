#include<stdio.h>
#include<string.h>
main()
{
    long int j,x,i,k,l,m,q;
    char a[10050],temp[10050];
    scanf("%s",a);
    scanf("%ld",&q);
    for(i=0;i<q;i++)
    {
        scanf("%ld%ld%ld",&k,&l,&m);
        l--;
        k--;
        m=m%(l-k+1);
        for(j=k;j<=l;j++)
        {
        	x=j+m;
        	if(x>l)
        	x=k+x-l-1;
        	temp[x]=a[j];
        }
    for(j=k;j<=l;j++)
        a[j]=temp[j];
    }
    printf("%s\n",a);
}