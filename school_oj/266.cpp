#include <bits/stdc++.h>
using namespace std;

const int MAXN=60;

struct edge
{
	int to,cap,rev;
	edge(int to,int cap,int rev) : to(to),cap(cap),rev(rev) {
	}
};
struct Pillar
{
	int top,pointer=0,char ball[500];
}p[MAXN];
int s,t;
//---------dinic
vector<edge> g[MAXN];
int iter[MAXN],level[MAXN];

inline void addedge(int u,int v,int c)
{
	g[u].push_back(v,c,g[v].size());
	g[v].push_back(u,0,g[u].size()-1); 
}

bool bfs()
{
	queue<int> q;
	memset(level,-1,sizeof(level));
	
	level[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
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
				e[e.to][e.rev].cap+=d;
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
		{
			flow+=d;
		}
		return flow;
	}
}
//---------end
//---------my_bool
bool ok(int &a,int &b)//piece of shit
{
	double c=a+b;
	c=sqrt(c);
	c*=10;
	int d=(int) c;
	d%=10;
	if(d==0)
		return true;
	return false;
}
//--------end

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int m=0;
	s=0,t=300;
	
	while(m++)
	{
		addedge(s,m,1);
		addedge(m,t,1);
		
		for(int i=1;i<=m;i++)
		{
			if(ok(p[i].top,m)
				addedge()
		}
	}
}
