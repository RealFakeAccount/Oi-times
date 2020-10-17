#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
//确定转向的方向
int dx[4]={0,-1,0,1};//纵向
int dy[4]={-1,0,1,0};//横向   
int a[20][20];
struct node
{
	 int x,y;//定义结构体
}b[4400];//b数组用于保存走过的路径，后缀.x代表行，.y后缀代表列
int stx,sty,edx,edy;//定义起点，终点
bool bk=false;//定义bool型返回值，且默认为0

void dfs(int x,int y,int k)
{
	b[k].x=x;b[k].y=y;
	if(x==edx&&y==edy)//如果走到终点了，准备打印结果
	{
		for(int i=1;i<k;i++)printf("(%d,%d)->",b[i].x,b[i].y);
		printf("(%d,%d)\n",b[k].x,b[k].y);
		bk=true;
	}
	else//没到终点就该判断转向的问题了
	{
		for(int i=0;i<=3;i++)
		{
			if(a[x+dx[i]][y+dy[i]]==1)
			{
				a[x+dx[i]][y+dy[i]]=0;
				dfs(x+dx[i],y+dy[i],k+1);
				a[x+dx[i]][y+dy[i]]=1;
			}
		}
	}
}
	
int main()
{ 
	int n,m;   //行数，列数定义好
	scanf("%d%d",&n,&m); //输入行列数
	memset(a,0,sizeof(a));//默认整个二维数组为不可用，免得输入了下面的迷宫后边界都没有，会出界
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);//输入迷宫地图，坐标轴循环输入
		}
	}
	scanf("%d%d",&stx,&sty);//输入起点
	scanf("%d%d",&edx,&edy);//输入终点
	bk=false;//初始化返回值为0(可省略，因为这个值定义下来就被初始化了）
	a[stx][sty]=0;//设起点不可用，免得被重复循环走几次
	dfs(stx,sty,1);//输入参数，开始递归
	if(bk==0) printf("-1\n");//如果返回值依旧为0，说明迷宫走不了，输出-1
	return 0; 
} 