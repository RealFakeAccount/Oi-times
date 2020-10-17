#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int solve(int x,int n)
{
	int z=(n+1)/2;
	int j=abs(z-x);
	int k=abs(j-n/2);
	int q=x+k;
	return q;
}

int main()
{
	int m,n,x,y,z,i;
	scanf("%d",&m);
	for(x=1;x<=m;x++)
	{
		z=(m+1)/2;
		i=abs(z-x);
		for(int a=1;a<=i;a++)
		{
			printf(" ");
		}
		int q=solve(x,m);
		for(y=1;y<=q;y++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}