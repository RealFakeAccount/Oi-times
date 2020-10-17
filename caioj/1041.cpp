#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
int n,a[40][40];
int ans=21474786;
bool v[110];
void mins(int k,int d,int last)
{
	if(d>=ans) return ;
	if(k==n+1)
	{
		if(d+a[last][1]<ans)
		{
			ans=d+a[last][1];
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(v[i])
			{
				if(d+a[last][i]>ans) return ;
				v[i]=false;
				mins(k+1,d+a[last][i],i);
				v[i]=true;
			}
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	memset(v,true,sizeof(v));
	v[1]=false;
	mins(2,0,1);
	printf("%d",ans);
	return 0;
}