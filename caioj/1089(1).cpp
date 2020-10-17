#include<string.h>
#include<cstdio>
#include<cstdlib>
using namespace std;

const int maxn=101;
const int maxint=1000000000;
int N;
int M;
int D;
int A,B;
bool s[maxn];
int dist[maxn],map1[maxn][maxn],map2[maxn][maxn];

void dijk(int v,int g[101][101],int n)
{
	int i,j,u,temp;
	for(i=1;i<=n;i++)
	{
		dist[i]=maxint;
		s[i]=false;
	}
	dist[v]=0;
	for(i=1;i<=n;i++)
	{
		temp=maxint;
		for(j=1;j<=n;j++)
		if(!s[j]&&(dist[j]<temp))
		{
			u=j;
			temp=dist[j];
		}
		s[u]=true;
		for(j=1;j<=n;j++)
		{
			if(!s[j]&&g[u][j]!=-1)
			{
				if(dist[j]>dist[u]+g[u][j])
				{
					dist[j]=dist[u]+g[u][j];
				}
			}
		}
	}
}

int main()
{
	int i,j,k;
	while(scanf("%d",&N),N)
	{
		memset(map1,-1,sizeof(map1));
		for(i=1;i<=N;i++)map1[i][i]=0;
		scanf("%d",&M);
		while(M--)
		{
			scanf("%d%d%d",&i,&j,&k);
			map1[i][j]=map1[j][i]=k;
		}
		for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
		if(map1[i][j]==-1)map2[i][j]=-1;
		else map2[i][j]=0;
		scanf("%d",&D);
		while(D--)
		{
			scanf("%d%d",&i,&j);
			map2[i][j]=map2[j][i]=map1[i][j];
		}
		scanf("%d%d",&A,&B);
		dijk(A,map2,N);
		printf("%d\n",dist[B]);
	}
	return 0;
}