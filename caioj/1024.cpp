#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int a,b,m,n,m1,n1;
	scanf("%d%d",&a,&b);
	for(m=a;m<=b;m++)
	{
		for(n=m;n<=b;n++)
		{
			m1=0;
			n1=0;
			for(int i=1;i<m;i++)
			{
				if(m%i==0)
				{
					m1=m1+i;
				}
			}
			for(int j=1;j<n;j++)
			{
				if(n%j==0)
				{
					n1=n1+j;
				}
			}
			if((m1==n)&&(n1==m)&&(m!=n))
			{
				printf("%d %d\n",m,n);
			}
		}
	}
	return 0;
}