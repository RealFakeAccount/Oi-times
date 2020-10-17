#include <cstdio>
#include <cmath>
//#include <iomanip>
using namespace std;

int main()
{
	int x,y,i,a,b,c,c1;
	scanf("%d%d",&x,&y);
	for(a=x;a<=y;a++)
	{
		for(b=a;b<=y;b++)
		{
			c1=a*a+b*b;
			c=sqrt(c1);
			if (c1==c*c&&c<=y)
			{
				printf("%d %d %d\n",a,b,c);
				
			}
		}
	}
	return 0;
}
