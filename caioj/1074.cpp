#include <cstdio>
#include <iostream>//基本输入流//基本输出流 
#include <algorithm>//STL 通用算法
#include <cstring>
using namespace std;

int f[201][201],s[201];
int n,i,j,k,x;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		s[i]=s[i-1]+x;
	}
	memset(f,21,sizeof(f));
	for(i=1;i<=n;i++)
		f[i][i]=0;
	for(i=n-1;i>=1;i--)
		for(j=i+1;j<=n;j++)
			for(k=i;k<=j-1;k++)
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
	cout<<f[1][n]<<endl;
	return 0;
}
