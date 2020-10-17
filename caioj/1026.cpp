#include <cstdio>
#include <iostream>
using namespace std;
int a[1111],l;
int judge(int x)
{
	l=0;
	while(x>0)
	{
		l++;
		a[l]=x%10;
		x=x/10;
	}
	for(int i=1;i<=l/2;i++)
	{
		if(a[i]!=a[l-i+1])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int x,y,i;
	scanf("%d%d",&x,&y);
	for(i=x;i<=y;i++)
	{
		if(judge(i)==1)
		{
			printf("%d\n",i);
		}
	}
	return 0;
}
