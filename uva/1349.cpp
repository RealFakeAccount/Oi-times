#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 100 + 20;
const int INF = 0x3f3f3f3f;

int N, S, T;

namespace MCMF
{
	struct _edge
	{
		int to, cost, cap, rev;
	};vector<_edge> g[MAXN << 1];

	int preve[MAXN << 1], prevv[MAXN << 1], dis[MAXN << 1];
	bool inq[MAXN << 1];

	inline void addedge(int u, int v, int c, int w)
	{
		g[u].push_back((_edge){v, w, c, g[v].size()});
		g[v].push_back((_edge){u, -w, 0, g[u].size() - 1});
	}

	inline bool tension(const int &st, int &lg)
	{return st < lg ? (lg = st, true) : false;}

	P mcmf(int s, int t)
	{
		P ans(0, 0);

		while(true)
		{
			deque<int> q;
			memset(inq, false, sizeof(inq));
			memset(dis, 0x3f, sizeof(dis));

			q.push_front(s);
			dis[s] = 0;
			inq[s] = true;
			while(!q.empty())
			{
				int u = q.front(); q.pop_front();
				for(int i = 0; i < (int) g[u].size(); i++)
				{
					_edge &e = g[u][i];
					if(e.cap && tension(dis[u] + e.cost, dis[e.to]))
					{
						preve[e.to] = i;
						prevv[e.to] = u;
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
			for(int i = t; i != s; i = prevv[i])
			{
				_edge &e = g[prevv[i]][preve[i]];
				e.cap -= flow;
				g[e.to][e.rev].cap += flow;
			}
		} 
		return ans;
	}
}

int main()
{
	using namespace MCMF;
	while(cin>>N, N)
	{
		S = 0, T = (N << 1) + 1;
		for(int i = 1; i <= N; i++) 
			addedge(S, i, 1, 0),
			addedge(i + N, T, 1, 0);
		for(int i = 1, v, c; i <= N; i++)
		{
			while(scanf("%d%d", &v, &c) == 2)
				addedge(i, v + N, 1, c);
		}
	}
	P ans = mcmf(S, T);
	if(ans.first == N) printf("%d\n", ans.second);
	else puts("N");
	return 0;
}