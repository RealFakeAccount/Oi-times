#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int n,r;
int a[110],b[110],ans;
int v[110];
int judge(int a)
{
	if (a==1)
	{
		return 0;
	}
	else
	{
		int t= sqrt(a+1);
		int i;
		for(i=2;i<=t;i++)
		{
			if(a%i==0)
			{
				return 0;
			}
		}
		return 1;
	}
}
void dfs(int k)
{
	if(k==r+1)
	{
		int s=0;
		for(int i=1;i<=r;i++)
		{
			s+=b[ a[i] ];
		}
		if(judge(s)==1)
		{
			ans++;
		}
	}
	else
	{
		for(int i=a[k-1]+1;i<=n;i++)
		{
			if(v[i]==1)
			{
				v[i]=0;
				a[k]=i;
				dfs(k+1);
				a[k]=0;
				v[i]=1;
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&r);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		v[i]=1;
	}
	ans=0;
	a[0]=0;
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
