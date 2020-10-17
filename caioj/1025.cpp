#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int a,b,c,d,i;
	scanf("%d%d",&a,&b);
	for(i=a;i<=b;i++)
	{
		c=i*i;
		d=1;
		while(d<i)
		{
			d=d*10;
		}
		if(c%d==i)
		{
			printf("%d\n",i);
		}
	}
	return 0;
}
