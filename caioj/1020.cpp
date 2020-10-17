#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int x,y,m,n,i;
	scanf("%d%d",&x,&y);
	
	for(i=x;i<=y;i++)
	{
		n=0;
		for(m=1;m<i;m++)
		{
			if(i%m==0)
			{
				n=n+m;
			}
		}
		if(n==i)
		{
			printf("%d\n",i);
		}
	}
	
	return 0;
}
