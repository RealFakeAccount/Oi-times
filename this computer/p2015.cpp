#include <bits/stdc++.h>
using namespace std;
const int MAXN=100+2;

int fa[MAXN][3],c[MAXN],f[MAXN][MAXN];
int dfs(int now,int j)
{
	if(j==0)
		f[now][j]=0;
	
	else if(fa[now][0]==0)
		f[now][j]=c[now];
	
	else
		for(int i=0;i<j;i++)
		{
			if(f[fa[now][1]][i]==0)
				dfs(fa[now][1],i);
			if(f[fa[now][2]][j-i-1]==0)
				dfs(fa[now][2],j-i-1);
			f[now][j]=max(f[now][j],f[fa[now][1]][i]+f[fa[now][2]][j-i-1]+c[now]);
		}
}
int main()
{
	ios::sync_with_stdio(false);
	int N,Q;
	cin>>N>>Q;
	
	int x,y,z;
	for(int i=1;i<N;i++)
	{
		cin>>x>>y>>z;
		++fa[x][0];
		fa[x][fa[x][0]]=y;
		c[y]=z;
	}
	
		
	dfs(1,Q+1);
	cout<<f[1][Q+1]<<endl;
	return 0;	
}
