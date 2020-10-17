#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>
using namespace std;
const int MAXN=60+2;
const int MAXM=9+1;
const int INF=0x7f7f7f7f;

namespace MCMF
{
	const int MAXNODE = MAXN+MAXN*MAXM;
	struct edge
	{
		int to,cost,cap,rev;
		edge(int to,int cost,int cap,int rev) : to(to),cost(cost),cap(cap),rev(rev) {
		}
	};
	
	vector<edge> g[MAXNODE];
	int dis[MAXNODE],preve[MAXNODE],prevv[MAXNODE];
	bool inq[MAXNODE];
	
	inline void addedge(int u,int v,int cap,int w)
	{
		g[u].push_back(edge(v,w,cap,g[v].size()));
		g[v].push_back(edge(u,-w,0,g[u].size()-1));
	}
	
	inline bool tension(int &a,const int &b)//dis[e.to],dis[u]+e.cost
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
			fill(dis,dis+MAXNODE+1,INF);
			
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
						prevv[e.to]=u;
						preve[e.to]=i;
						if(!inq[e.to])
						{
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


int T[MAXN][MAXM];

int main()
{
	int N,M;
	cin>>M>>N;
	
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			cin>>T[i][j];
			
	int s,t;
	s=0,t=MCMF::MAXNODE;
	
	for(int i=1;i<=N;i++)	
		MCMF::addedge(s,i,1,0);
		
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			for(int k=1;k<=N;k++)
				MCMF::addedge(i,j*N+k,1,T[i][j]*k);
	for(int i=1;i<=M;i++)
		for(int j=1;j<=N;j++)
			MCMF::addedge(i*N+j,t,1,0);
			
	pair<int,int> ans=MCMF::mincostmaxflow(s,t);
	
	printf("%.2lf\n",(double) ans.second/N);
	return 0;
}
