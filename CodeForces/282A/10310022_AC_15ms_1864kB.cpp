#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
int main() 
    { 
    int n,i,j,x=0; 
    scanf("%d",&n); 
    char c[4]; 
    for(i=0;i<n;i++) 
        { 
        scanf("%s",&c); 
        if(strcmp(c,"X++")==0||strcmp(c,"++X")==0) 
        x++; 
        else if(strcmp(c,"X--")==0||strcmp(c,"--X")==0) 
        x--; 
        } 
    printf("%d",x); 
    return 0; 
    }