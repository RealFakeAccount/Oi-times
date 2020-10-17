#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
int n,m,a[210];
int ans;
bool v[210];
void dfs(int k,int d,int last)
{
	if(ans==m) return ;
	if(abs(ans-m)>abs(d-m))ans=d;
	if(k==n+1) return ;
	for(int i=last+1;i<=n;i++)
	{
		if(v[i]==false)
		{
			if(i+d<=m||abs(ans-m)>abs(d-m))
			{
				v[i]=true;
				dfs(k+1,d+a[i],i);
				v[i]=false;
			}
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	memset(v,false,sizeof(v));
	ans=0;
	dfs(1,0,0);
	printf("%d\n",ans);
	return 0;
}
