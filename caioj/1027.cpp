#include <cstdio>
#include <iostream>
//#include <iomanip>
using namespace std;

int main()
{
	int x,y,i,a,b,c;
	scanf("%d%d",&x,&y);
	for(i=x;i<=y;i++)
	{
		a=i%10;
		b=i/10%10;
		c=i/100;
		
		if(a*a*a+b*b*b+c*c*c==i)
		{
			printf("%d\n",i);
		}
	}
	return 0;
}
