#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int x,y,a,b,i,j,sa,sb;
	scanf("%d%d",&x,&y);
	for(i=x;i<=y;i++)
	{
		a=i;sa=0;
		for(j=1;j<a;j++)
		{
			if(a%j==0)
			{
				sa=sa+j;
			}
		}
		b=sa;sb=0;
		for(j=1;j<=b/2;j++)
		{
			if(b%j==0)
			{
				sb=sb+j;
			}
		}
		if(a==sb&&a<b)
		{
			printf("%d %d\n",a,b);
		}
	}
	return 0;
}