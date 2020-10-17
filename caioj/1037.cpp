#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
int a[20][20];
int stx,sty,enx,eny;
struct node
{
	int x,y;
}b[4400];
bool bk=false;
void run(int x,int y,int k)
{
	b[k].x=x;
	b[k].y=y;
	if(x==enx&&y==eny)
	{
		for(int i=1;i<k;i++)
			printf("(%d,%d)->",b[i].x,b[i].y);
			printf("(%d,%d)\n",b[k].x,b[k].y);
			bk=true;
	}
	else
	{
		for(int i=0;i<=3;i++)
		{
			if(a[ x + dx[i] ][ y + dy[i] ]==1)
			{
				a[ x + dx[i] ][ y + dy[i] ]=0;
				run(x+dx[i],y+dy[i],k+1);
				a[x+dx[i]][y+dy[i]]=1;
			}
		}
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d%d",&stx,&sty);
	scanf("%d%d",&enx,&eny);
	bk=false;
	a[stx][sty]=0;
	run(stx,sty,1);
	if(bk==false)
		printf("-1/n");
	return 0;
}

