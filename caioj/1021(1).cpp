#include<stdio.h>
#include<stdlib.h>
int main()
{
 int n,i,j;
 scanf("%d",&n);
n=(n+1)/2;
 for(i=1-n;i<=n-1;i++)
 {
for(j=0;j<abs(i);j++)
  printf(" ");
for(j=0;j<2*(n-abs(i))-1;j++)
printf("*");
printf("\n");
 }
 return 0;
}