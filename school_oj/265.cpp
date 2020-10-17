#include <bits/stdc++.h>
using namespace std;
const int MAXN=150+10;	

int m,n,s,t;
bool vis[MAXN*2];
//----------
struct edge
{
	int to,cap,rev;
	edge(int to,int cap,int rev) : to(to),cap(cap),rev(rev) {
	}
};
//---------dinic
vector<edge> g[MAXN*2];
int iter[MAXN*2],level[MAXN*2];

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
		int u=q.front();
		q.pop();
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
//---------end
void printpath(int id) 
{
	if (id < 0) return;
    cout<<id<<" ";
    for (int i = 0; i <(int) g[id].size(); i++)
        if(vis[g[id][i].to] && !g[id][i].cap)
            printpath(g[id][i].to - n);
    
}


int main()
{
	//freopen("265.txt","r",stdin);
	ios::sync_with_stdio(false);

	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		addedge(0,i,1);
		addedge(n+i,2*n+1,1);
	}
	
	int u,v;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		addedge(u,v+n,1);
	}
	
	s=0;t=2*n+1;
	int ans=maxflow();
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++)
		for(int j=0;j<(int) g[i].size();j++)
			if(!g[i][j].cap)
				vis[g[i][j].to]=true;
		
	for(int i=1;i<=n;i++)
		if(!vis[i+n])
		{
			printpath(i);
			cout<<endl;
		}
	cout<<n-ans<<endl;
	
	
	return 0;
}

