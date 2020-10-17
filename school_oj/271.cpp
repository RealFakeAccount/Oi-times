#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
const int MAXN=30+5;

struct edge
{
	int to,cap,rev;
	edge(int to,int cap,int rev) : to(to),cap(cap),rev(rev) {
	}
};

int m,n;
int p[MAXN*2];
//------------dinic
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
	
	level[s]=0;
	q.push(s);
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
			int d=dfs(e.to,min(flow,e.cap));
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
//------------end
//--------other
inline bool dye(int i,int j)
{
	return (i+j)%2;
}
inline int num(int i,int j)
{
	return (i-1)*n+j;
}
//--------end

int main()
{
	freopen("271.txt","r",stdin);
	ios::sync_with_stdio(false);
	
	
	int tc=0;//totalcost
	cin>>m>>n;
	s=0,t=n*m+1;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			cin>>p[num(i,j)];
			tc+=p[num(i,j)];
			
			if(dye(i,j))
				addedge(s,num(i,j),p[num(i,j)]);
			else
				addedge(num(i,j),t,p[num(i,j)]);
			
			if(dye(i,j))
			{	
				if(i-1>=1)
					addedge(num(i,j),num(i-1,j),INT_MAX);
				if(i+1<=m)
					addedge(num(i,j),num(i+1,j),INT_MAX);
				if(j+1<=n)
					addedge(num(i,j),num(i,j+1),INT_MAX);
				if(j-1>=1)
					addedge(num(i,j),num(i,j-1),INT_MAX);
			}
		}
		
	cout<<tc-maxflow()<<endl;
	
	return 0;
}
