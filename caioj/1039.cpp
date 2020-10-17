#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
int dx[8]={-2,-1,-2,1,2,2,1,-1};
int dy[8]={-1,2,1,2,1,-1,-2,-2};
int a[11][11],n;
bool bk;
void dfs(int k,int x,int y)
{
	if(bk==true) return;
	if(k==n*n+1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<n;j++)
			{
				printf("%d ",a[i][j]);
			}
			printf("%d\n",a[i][n]);
		}
		bk=true;
	}
	else
	{
		for(int i=0;i<=7;i++)
		{
			int xx=x+dx[i],yy=y+dy[i];
			if((xx)>0&&(xx)<=n&&(yy)>0&&(yy)<=n)
			{
				if(a[xx][yy]==0)
				{
					a[xx][yy]=k;
					dfs(k+1,xx,yy);
					a[xx][yy]=0;
				}
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	bk=false;
	a[1][1]=1;
	dfs(2,1,1);
	if(bk==false)
	{
		printf("-1\n");
	}
	return 0;
}
