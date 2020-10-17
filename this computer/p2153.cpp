#include <bits/stdc++.h>
using namespace std;
const int MAXN=200+5;
const int INF=0x7f7f7f7f;

namespace MCMF
{
	struct edge
	{
		int to,cost,cap,rev;
		edge(int to,int cost,int cap,int rev) : to(to),cost(cost),cap(cap),rev(rev) {
		}
	};
	
	vector<edge> g[MAXN<<1];
	int preve[MAXN<<1],prevv[MAXN<<1],dis[MAXN<<1];
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
			deque<int> q;
			memset(inq,false,sizeof(inq));
			fill(dis,dis+MAXN+1,INF);
			
			q.push_front(s);
			dis[s]=0;
			inq[s]=true;
			while(!q.empty())
			{
				int u=q.front();q.pop_front();
				inq[u]=false;
				for(int i=0;i<(int) g[u].size();i++)
				{
					edge &e=g[u][i];
					if(e.cap && tension(dis[e.to],dis[u]+e.cost))
					{
						preve[e.to]=i;
						prevv[e.to]=u;
						if(!inq[e.to])
						{
							inq[e.to]=true;
							if(q.empty() || dis[q.front()]<dis[e.to])
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
	int N,M;
	cin>>N>>M;
	
	int u,v,c;
	while(M--)
	{
		cin>>u>>v>>c;
		if(u==1)
			addedge(u,v,1,c);		
		else
			addedge(N+u,v,1,c);
	}
	for(int i=2;i<N;i++)
		addedge(i,N+i,1,0);
	
	pair<int,int> ans=mincostmaxflow(1,N);
	cout<<ans.first<<" "<<ans.second<<endl;
	return 0;
}
