#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000+10000+10;
const int INF=0x7f7f7f7f;
struct edge
{
	int to,cost,cap,rev;
	edge(int to,int cost,int cap,int rev) : to(to),cost(cost),cap(cap),rev(rev){
	}
};

namespace MCMF
{
	vector<edge> g[MAXN];
	int dis[MAXN],preve[MAXN],prevv[MAXN];
	bool inq[MAXN];
	
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
			deque<int> q;
			q.push_front(s);
			memset(inq,0,sizeof(inq));
			fill(dis,dis+MAXN+1,INF);
			
			dis[s]=0;
			inq[s]=true;
			
			while(!q.empty())
			{
				int u=q.front();
				q.pop_front();
				inq[u]=false;
				for(int i=0;i<(int)g[u].size();i++)
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
			if(dis[t]==INF)
				break;
				
			int flow=INF;
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
}

using namespace MCMF;

int main()
{
	ios::sync_with_stdio(false);
	int a,b,c,m,n;
	cin>>n>>m;
	
	s=0,t=m+n+1;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		addedge()
	}
	
	return 0;
}

