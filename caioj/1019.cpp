#include <cstdio>
#include <iostream>
using namespace std;

int f[31][31];
int main()
{
	int a,b,x,m,n;
	scanf("%d",&x);
	for(a=1;a<=x;a++)
	{
		f[a][1]=1;
	}
	for(a=1;a<=x;a++)
	{
		f[a][a]=1;
	}
	
	for(a=3;a<=x;a++)
	{
		for(b=2;b<=a-1;b++)
		{
			f[a][b]=f[a-1][b]+f[a-1][b-1];
		}
	}
	
	for(m=1;m<=x;m++)
	{
		for(n=1;n<=m;n++)
		{
			printf("%d ",f[m][n]);
		}
		printf("\n");
	}
	return 0;
}