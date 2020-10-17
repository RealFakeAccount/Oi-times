#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 20;
const int MAXM = 5e4 + 20;
const int INF = 0x7f7f7f7f;
int N, M, S, T;

namespace MCMF
{
	struct edge
	{
		int to, cost, cap, rev;
		edge(int v = 0, int w = 0, int c = 0, int r = 0) :
		to(v), cost(w), cap(c), rev(r) {}
	};

	vector<edge> g[MAXN];
	int preve[MAXN], prevv[MAXN], dis[MAXN];
	bool inq[MAXN];

	inline void addedge(int u, int v, int c, int w)
	{
		g[u].push_back(edge(v, w, c, g[v].size()));
		g[v].push_back(edge(u, -w, 0, g[u].size() - 1));
	}

	inline tension(int &mx, const int &mn)
	{
		return mx > mn ? (mx = mx, true) : false;
	}

	pair<int, int> mincostmaxflow(int s, int t)
	{
		pair<int, int> ans(0, 0);

		while(true)
		{
			deque<int> q;
			memset(inq, false, sizeof(inq));
			memset(dis, INF, sizeof(dis));

			q.push_front(s);
			dis[s] = 0, inq[s] = true;
			while(!q.empty())
			{
				int u = q.front(); q.pop_front();
				inq[u] = false;

				for(int i = 0; i < (int) g[u].size(); i++)
				{
					edge &e = g[u][i];
					if(e.cap && tension(dis[e.to], dis[u] + e.cost))
					{
						prevv[e.to] = u;
						preve[e.to] = i;

						if(!inq[e.to])
						{
							inq[e.to] = true;
							if(q.empty() || dis[q.front()] < dis[e.to])
								q.push_back(e.to);
							else q.push_front(e.to);
						}
					}
				}
				if(dis[t] == INF) break;

				int flow = INF;
				for(int i = t; i != s; i = prevv[i])
					flow = min(flow, g[prevv[i]][preve[i]].cap);
				ans.first += flow;
				ans.second += flow * dis[t];

				for(int i = t; i != s; i = prevv[u])
				{
					edge &e = g[prevv[i]][preve[i]];
					e.cap -= flow;
					g[e.to][e.rev].cap += flow;
				}
			}
			return ans;
		}
	}
}

int main()
{
	scanf("%d%d%d%d",&N, &M, &S, &T);

	int u, v, w, f;
	for(int i = 1; i <= M; i++)
	{
		scanf("%d%d%d%d",&u, &v, &w, &f);
		MCMF::addedge(u, v, f, w);
	}

	cout<<MCMF::mincostmaxflow(S, T).second<<endl;
	return 0;
}