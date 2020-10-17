#include <bits/stdc++.h>
using namespace std;
const int MAXN=200+5;

int N;
namespace dijks
{
	typedef pair<int,int> P;
	struct edge
	{
		int to,cost;
		edge(int to,int cost) : to(to),cost(cost){
		}
	};
	vector<edge> g[MAXN];
	int d[MAXN];
	
	inline void addedge(int u,int v,int c)
	{
		g[u].push_back(edge(v,c));
	}

	bool tension(int &a,const int &b)
	{
		return a>b ? (a=b,true) : false;
	}
	int dijkstra(int s,int t)
	{
 		priority_queue<P,vector<P>,greater<P> > Q;
 		fill(d,d+N+1,INT_MAX);
 		d[s]=0;Q.push(P(0,s));
 		while(!Q.empty())
 		{
 			P p=Q.top(); Q.pop();
 			int v=p.second;
 			if(d[v]<p.first)
 				continue;
 			for(int i=0;i<(int)g[v].size();i++)
 			{
 				edge &e=g[v][i];
 				if(tension(d[e.to],d[v]+e.cost))
 					Q.push(P(d[e.to],e.to));
 			}
 		}
 		return d[t];
	}
}

using namespace dijks;

int main()
{
	cin>>N;
	for(int i=1;i<N;i++)
		for(int j=i+1;j<=N;j++)
		{
			int w;
			cin>>w;
			addedge(i,j,w);
		}

	cout<<dijkstra(1,N)<<endl;
	return 0;
}