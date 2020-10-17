#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int n;
int a[110];
void dfs(int k,int s)
{
	if(s==0)
	{
		return ;
	}
	if (k>1)
	{
		a[k]=s;
		if(a[k-1]<=a[k])
		{
			for(int i=1;i<=k-1;i++)
			{
				printf("%d+",a[i]);
			}
			printf("%d\n",a[k]);
		}
	}
	{
		for(int i=a[k-1];i<=s;i++)
		{
			a[k]=i;
			dfs(k+1,s-i);
			a[k]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	a[0]=1;
	dfs(1,n);
	return 0;
}
