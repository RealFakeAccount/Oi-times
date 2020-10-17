#include <bits/stdc++.h>
using namespace std;
const int MAXN=5000+10;

struct edge
{
	int to,cost,cap,rev;
	edge(int to,int cost,int cap,int rev) : to(to),cost(cost),cap(cap),rev(rev)
	{
	}
};
//----------MCMF
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
	if(a>b)
	{
		a=b;
		return true;
	}
	return false;
}

pair<int,int> mincostmaxflow(int s,int t)
{
	pair<int,int> ans(0,0);
	while(1)
	{
		deque<int> q;
		fill(dis,dis+MAXN+1,INT_MAX);
		memset(inq,0,sizeof(inq));

		q.push_front(s);
		dis[s]=0;
		inq[s]=true;

		while(!q.empty())
		{
			int u=q.front();
			q.pop_front();
			inq[u]=false;
			for(int i=0; i<(int) g[u].size(); i++)
			{
				edge &e=g[u][i];
				if(e.cap && tension(dis[e.to],dis[u]+e.cost))
				{
					prevv[e.to]=u;
					preve[e.to]=i;
					if(!inq[e.to]) 
					{
						inq[e.to] = 1;
						if(q.empty() || dis[e.to] > dis[q.front()]) 
						q.push_back(e.to);
						else q.push_front(e.to);
					}
				}
			}
		}
        //	cout<<dis[t]<<endl;
		if(dis[t]==INT_MAX)
			break;


		int flow=INT_MAX;
		for(int i=t; i!=s; i=prevv[i])
			flow=min(flow,g[prevv[i]][preve[i]].cap);
		ans.first+=flow;
		ans.second+=flow*dis[t];
		//	cout<<ans.first<<" "<<ans.second<<endl;
		for(int i=t; i!=s; i=prevv[i])
		{
			edge &e=g[prevv[i]][preve[i]];
			e.cap-=flow;
			g[e.to][e.rev].cap+=flow;
		}
	}
	return ans;

}
//----------end

int main()
{
//	freopen("p3381.txt","r",stdin);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;

	int u,v,c,w;
	for(int i=0; i<n; i++)
		for(int j=0;j<n;j++)
		{
			cin>>u;
		}
	
	
	pair<int,int> ans=mincostmaxflow(s,t);
	cout<<ans.second<<endl;
	return 0;
}
