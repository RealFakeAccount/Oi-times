#include <bits/stdc++.h>
using namespace std;
const int MAXN=2000+5;

struct edge
{
	int to,cost,cap,rev;
	edge(int to,int cost,int cap,int rev) : to(to),cost(cost),cap(cap),rev(rev) {
	}
};
//----------MCMF

vector<edge> g[MAXN<<1];
int dis[MAXN<<1],preve[MAXN<<1],prevv[MAXN<<1];
bool inq[MAXN<<1];

inline void addedge(int u,int v,int cap,int w)
{
	g[u].push_back(edge(v,w,cap,g[v].size()));
	g[v].push_back(edge(u,-w,0,g[u].size()-1));
}

inline bool tension(int &a,const int &b)
{
	return a>b ? (a=b,true) : false;
}

pair<int,int> mincostmaxflow(int s,int t)
{
	pair<int,int> ans(0,0);
	while(true)
	{
		deque<int>q;
		q.push_front(s);
		memset(inq,0,sizeof(inq));
		fill(dis,dis+MAXN+1,INT_MAX);
		
		dis[s]=0;
		inq[s]=true;
		
		while(!q.empty())
		{
			int u=q.front();
			q.pop_front();
			inq[u]=false;
			for(int i=0;i<(int) g[u].size();i++)
			{
				edge &e=g[u][i];
				if(e.cap && tension(dis[e.to],dis[u]+e.cost))
				{
					prevv[e.to]=u;
					preve[e.to]=i;
					if(!inq[e.to])
					{
						inq[e.to]=true;
						if(q.empty() || dis[e.to]>dis[q.front()])
							q.push_back(e.to);
						else
							q.push_front(e.to);
					}
				}
			}
		}
		if(dis[t]==INT_MAX)
			break;
			
		int flow=INT_MAX;
		for(int i=t;i!=s;i=prevv[i])
			flow=min(flow,g[prevv[i]][preve[i]].cap);
		ans.first+=flow;
		ans.second+=flow*dis[t];
		
		for(int i=t;i!=s;i=prevv[i])
		{
			edge &e=g[prevv[i]][preve[i]];
			e.cap-=flow;
			g[e.to][e.rev].cap+=flow;
		}
	}
	return ans;
}

//----------end;

int main()
{
	ios::sync_with_stdio(false);
//	freopen("p1251.txt","r",stdin);
	int N,s,t;
	cin>>N;	
	
	s=0,t=(N<<1)+1;
	
	int ca;
	for(int i=1;i<=N;i++)
	{
		cin>>ca;
		addedge(s,i,ca,0);
		addedge(i+N,t,ca,0);
	}
	int p,m,f,n,si;
	cin>>p>>m>>f>>n>>si;
	
	
	for(int i=1;i<=N;i++)
	{
		addedge(s,N+i,INT_MAX,p);
		if(i<=N-m)
			addedge(i,i+N+m,INT_MAX,f);
		if(i<=N-n)
			addedge(i,i+N+n,INT_MAX,si);
		if(i<=N-1)
			addedge(i,i+1,INT_MAX,0);
	}
	
	pair<int,int> ans=mincostmaxflow(s,t);
	cout<<ans.second<<endl;
	return 0;
}


