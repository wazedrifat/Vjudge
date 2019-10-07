#include<stdio.h>
int main()
{
    int H,M,i,j,m=0,m1=0,m2=0;
    scanf("%d:%d",&H,&M);
    for(M=M+1;;M++)
    {
        if(M==60)
        {
            M=0;
            H++;
            if(H==24)
            H=0;
        }
        m2=M%10;
        m1=M/10;
        m=m1+(m2*10);
        if(m==H)
        {
            printf("%.2d:%.2d",H,M);
            return 0;
        }
    }
}