#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,i,j,k,c,d,e;
    char a[6],b[6];
    for(k=0,c=0;scanf("%d%d",&n,&m)!=EOF;k++)
    {
        for(i=n,c=0;i<=m;i++)
        {
            snprintf(a,5,"%d",i);
            for(j=0;a[j]!='\0';j++)
            {
                for(d=j+1,e=0;a[d]!='\0';d++)
                {
                    if(a[d]==a[j])
                    {
                        e=1;
                        break;
                    }
                }
                if(e==1)
                    break;
            }
            if(e==0)
                c++;
        }
        printf("%d\n",c);
    }
}
