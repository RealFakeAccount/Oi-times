#include <bits/stdc++.h>
using namespace std;
const int MAXN=500+10;

struct edge
{
	int to,cap,rev;
	edge(int to,int cap,int rev) : to(to),cap(cap),rev(rev)
	{
	}
};

int f[MAXN],a[MAXN];
int n;
//-------dp
int dp()
{
	fill(f,f+n+1,0);
	int maxans=0;
	for(int i=1; i<=n; i++)
	{
		f[i]=1;
		for(int j=1; j<i; j++)
		{
			if(a[j]<=a[i])
				f[i]=max(f[i],f[j]+1);
		}
		maxans=max(f[i],maxans);
	}
	return maxans;
}
//-------end
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
		int u=q.front();
		q.pop();
		for(int i=0; i<(int) g[u].size(); i++)
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

	for(int &i=iter[u]; i<(int) g[u].size(); i++)
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
	for(int i=1; i<=MAXN; i++)
		g[i].clear();
}
//-------end


int main()
{
//	freopen("269.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];

	int maxdp=dp();
	cout<<maxdp<<endl;

	if(maxdp==1)//remember this spj
		cout<<n<<endl<<n<<endl;

	else
	{
		s=0,t=2*n+1;
		for(int i=1; i<=n; i++)
		{
			addedge(i,i+n,1);

			if(f[i]==1)
				addedge(s,i,1);

			if(f[i]==maxdp)
				addedge(i+n,t,1);

			for(int j=1; j<i; j++)
				if(a[j]<=a[i] && f[i]==f[j]+1)
					addedge(j+n,i,1);
		}

		cout<<maxflow()<<endl;

		clear();
		for(int i=1; i<=n; i++)
		{

			if(i==1||i==n)
			{
				if(f[i]==1)
					addedge(s,i,INT_MAX);
				addedge(i,i+n,INT_MAX);
				if(f[i]==maxdp)
					addedge(i+n,t,INT_MAX);
			}
			else
			{
				if(f[i]==1)
					addedge(s,i,1);
				addedge(i,i+n,1);
				if(f[i]==maxdp)
					addedge(i+n,t,1);
			}
			for(int j=1; j<i; j++)
				if(a[j]<=a[i]&&f[j]+1==f[i])
					addedge(j+n,i,1);
		}
		cout<<maxflow()<<endl;
	}

	return 0;
}

