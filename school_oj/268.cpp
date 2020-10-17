#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;
const int MAXN=150+270+10;

struct edge
{
	int to,cap,rev;
	edge(int to,int cap,int rev) : to(to),cap(cap),rev(rev) {
	}
};
int s,t;
//-------dinic
vector<edge> g[MAXN];
int iter[MAXN],level[MAXN];

inline void addedge(int u,int v,int c)
{
	g[u].push_back(edge(v,c,g[v].size()));
	g[v].push_back(edge(u,0,g[u].size()-1));
}

bool bfs()
{
	queue<int> q;
	memset(level,-1,sizeof(level));
	
	q.push(s);
	level[s]=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=0;i<(int)g[u].size();i++)
		{
			edge &e=g[u][i];
			if(e.cap && level[e.to]==-1)
			{
				level[e.to]=level[u]+1;
				q.push(e.to);
			}
		}
	}
	return ~level[t];
}

int dfs(int u,int flow)
{
	if(u==t)
		return flow;
	
	for(int &i=iter[u];i<(int) g[u].size();i++)
	{
		edge &e=g[u][i];
		if(e.cap && level[e.to]==level[u]+1)
		{
			int d=dfs(e.to,min(e.cap,flow));
			if(d)
			{
				e.cap-=d;
				g[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

long long maxflow()
{
	long long flow=0,d=0;
	while(bfs())
	{
		memset(iter,0,sizeof(iter));
		while(d=dfs(s,INT_MAX),d)
			flow+=d;
	}
	return flow;
}
//-------end

int main()
{
//	freopen("268.txt","r",stdin);
	ios::sync_with_stdio(false);
	int m,n;
	cin>>m>>n;
	s=0,t=m+n+1;
	
	for(int i=1;i<=m;i++)
		for(int j=m+1;j<=n+m;j++)
			addedge(i,j,1);

	int c,sum=0;
	for(int i=1;i<=m;i++)
	{
		cin>>c;
		addedge(s,i,c);
		sum+=c;
	}
	for(int i=m+1;i<=m+n;i++)
	{
		cin>>c;
		addedge(i,t,c);
	}
	
	int cache=maxflow();
	if(cache==sum)
	{
		cout<<1<<endl;
		for(int i=1;i<=m;i++)
		{
			for(int j=0;j<(int) g[i].size();j++)
			{
				edge &e=g[i][j];
				if(e.cap==0)
					cout<<e.to-m<<" ";
			}
			cout<<endl;
		}
	}
	else
		cout<<0<<endl;
		
	
}

