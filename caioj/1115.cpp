#include <bits/stdc++.h>
using namespace std;
const int MAXN=200+10;

struct edge
{
	int to,cap,rev;
	edge(int to,int cap,int rev) : to(to),cap(cap),rev(rev) {
	}
};
//-------dinic
vector<edge> g[MAXN];
int iter[MAXN],level[MAXN],s,t;

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
		for(int i=0;i<(int) g[u].size();i++)
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
	ios::sync_with_stdio(false);
	int m,n,e;
	cin>>n>>m>>e;
	
	int u,v;
	s=0;t=n+m+1;
	for(int i=1;i<=e;i++)
	{
		cin>>u>>v;
		if(u<=n && v<=m)
			addedge(u,v,1);
	}
	for(int i=1;i<=n;i++)
		addedge(s,i,1);
	
	for(int i=n+1;i<=m;i++)
		addedge(i,t,1);
		
	cout<<maxflow()<<endl;
}

