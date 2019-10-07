#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,x;
    scanf("%d",&n);
    char c[n][15];
    char Cube=6,Tetrahedron=4,Octahedron=8,Dodechedron=12,Icosahedeon=20;
    for(i=0;i<n;i++)
    {
        scanf("%s",&c[i]);
    }
    x=0;
    for(i=0;i<n;i++)
    {
        if(c[i][0]==84)
        {
            x=x+4;
           
        }
        else if(c[i][0]==67)
        {
            x=x+6;
            
        }
        else if(c[i][0]==79)
        {
            x=x+8;
            
        }
        else if(c[i][0]==68)
        {
           x=x+12;
           
        }
        else if(c[i][0]==73)
        {
            x=x+20;
            
        }
    }
    printf("%d",x);
    return 0;
}