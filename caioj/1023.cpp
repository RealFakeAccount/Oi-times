#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	int m,n;
	m=0;
	scanf("%d",&n);
	while(n!=1)
	{
		if(n%2==0)
		{
			n=n/2;
		}
		else
		{
			n=3*n+1;
		}
		m++;
	}
	printf("%d",m);

	return 0;
}
