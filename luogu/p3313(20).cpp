#include <bits/stdc++.h>
using namespace std;
const int MAXN=100000+5;

struct node
{
	int w,c;
}nodes[MAXN];

namespace dijkstra
{
	vector<int> g[MAXN];
	int d[MAXN],prevv[MAXN],preve[MAXN];
	int s,t;
	typedef pair<int,int> P;

	
	void sdijkstra()
	{
		priority_queue<P,vector<P>,greater<P> > q;
		memset(d,63,sizeof(d));
		memset(prevv,0,sizeof(prevv));
		memset(preve,0,sizeof(preve));

		d[s]=0;
		q.push(P(0,s));
		while(!q.empty())
		{
			P p=q.top();q.pop();
			int v=p.second;
			if(d[v]<p.first)
				continue;
			for(int i=0;i<(int) g[v].size();i++)
			{
				int &e=g[v][i];
				if(d[v]+1<d[e])
				{
					prevv[e]=v;
					preve[e]=i;
					d[e]=d[v]+1;
					q.push(P(d[e],e));
				}
			}
		}
	}

	P solve()//1->QS(sum w),2->QM(max w)
	{
		P ans(0,0);
		for(int i=t;i!=s;i=prevv[i])
		{
			if(nodes[i].c==nodes[s].c)
			{
				ans.first+=nodes[i].w;
				ans.second=max(ans.second,nodes[i].w);
			}
		}
		ans.first+=nodes[s].w,ans.second=max(ans.second,nodes[s].w);
		return ans;
	}

}

using namespace dijkstra;

int main()
{
	int N,Q;
	scanf("%d %d",&N,&Q);
	for(int i=1;i<=N;i++)
		scanf("%d %d",&nodes[i].w,&nodes[i].c);
	for(int i=1;i<=N-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}

	P ans(0,0);
	while(Q--)
	{
		string in;int x,y;
		cin>>in;
		scanf(" %d %d",&x,&y);
		if(in=="CC")
		{
			nodes[x].c=y;
		}
		else if(in=="CW")
		{
			nodes[x].w=y;
		}
		else if(in=="QS")
		{
			s=x,t=y;
			sdijkstra();
			ans=solve();
			printf("%d\n",ans.first);
		}
		else if(in=="QM")
		{
			s=x,t=y;
			sdijkstra();
			ans=solve();
			printf("%d\n", ans.second);
		}
	}
	return 0;
}

