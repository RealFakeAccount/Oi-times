#include <iostream>//基本输入流//基本输出流 
#include <algorithm>//STL 通用算法
using namespace std;

int f[51][51][51][51]={0};
int a[51][51],m,n;

int mymax(int q,int w,int e,int r)
{
	int t=max(max(max(q,w),e),r);
	return t;
}

int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(int x=1;x<=m;x++)
				for(int y=1;y<=n;y++)
				{
					f[i][j][x][y]=mymax(f[i-1][j][x-1][y],f[i-1][j][x][y-1],f[i][j-1][x-1][y],f[i][j-1][x][y-1])+a[i][j]+a[x][y];
					if((i==x)&&(j==y))
					{
						f[i][j][x][y]-=a[i][j]+a[x][y];
					}
				}
	cout<<f[m][n][m][n]<<endl;
	return 0;
}
