#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000000;

struct edge
{
	int to,cap,rev;
	edge(int to,int cap,int rev) : to(to),cap(cap),rev(rev) {
	}
};
//-------dinic
vector<edge> g[MAXN*2];
int iter[MAXN*2],level[MAXN*2],s,t;

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

void clear()
{
	for(int i=1;i<=MAXN;i++)
		g[i].clear();
}
//-------end
int main()
{
	ios::sync_with_stdio(false);
	int m,n,u,v,c;
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>c;
		addedge(u,v,c);
	}
	
	cout<<maxflow()<<endl;
}
/*
7 14 1 7
1 2 5
1 3 6
1 4 5
2 3 2
2 5 3
3 2 2
3 4 3
3 5 3
3 6 7
4 6 5
5 6 1
6 5 1
5 7 8
6 7 7
ans is 14*/


