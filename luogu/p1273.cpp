#include <bits/stdc++.h>
using namespace std;
const int N=3010;
int n,m,EdgeCnt=0;
int dp[N][N],val[N],a[N],t[N];
struct Edge
{
	int to,w,next;
} e[N*N];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0' || ch>'9')
	{
		if (ch=='-')f=-1;
		ch=getchar();
	}
	while ('0'<=ch && ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void addedge(int u,int v,int w)
{
	int p=++EdgeCnt;
	e[p].to=v;
	e[p].w=w;
	e[p].next=a[u];
	a[u]=p;
}
int dfs(int u)
{
	if (u>n-m)
	{
		dp[u][1]=val[u];
		return 1;
	}
	int sum=0;
	for (int p=a[u]; p; p=e[p].next)
	{
		int v=e[p].to;
		int tk=dfs(v);
		for (int j=0; j<=sum; j++)t[j]=dp[u][j];
		for (int j=0; j<=sum; j++)
			for (int k=0; k<=tk; k++)
				dp[u][j+k]=max(dp[u][j+k],t[j]+dp[v][k]-e[p].w);
		sum+=tk;
	}
	return sum;
}
int main()
{
	n=read(),m=read();
	memset(dp,~0x3f,sizeof(dp));
	for (int u=1; u<=n-m; u++)
	{
		int size=read();
		for (int j=1; j<=size; j++)
		{
			int v=read(),w=read();
			addedge(u,v,w);
		}
	}
	for (int i=n-m+1; i<=n; i++)
		val[i]=read();
	for (int i=1; i<=n; i++)
		dp[i][0]=0;
	dfs(1);
	for (int i=m; i>0; i--)
		if (dp[1][i]>=0)
		{
			printf("%d",i);
			break;
		}
	return 0;
}
