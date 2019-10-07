#include<stdio.h>
int main()
{
	int n,a,b,c,d=0;
	scanf("%d",&n);
	a=n%7;
  if(a>2)
   c=2;
  else
    c=n%7;
  if(a==6)
    d=1;
  b=(n/7)*2;
  printf("%d %d",b+d,b+c);
	return 0;
} 