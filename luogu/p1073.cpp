#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 100000 + 20;
const int MAXM = 500000 + 20;
const int INF = 0x3f3f3f3f;

int N, M, C[MAXN];

inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

namespace dij
{
	vector<int> g[MAXN], rg[MAXN];
	int d1[MAXN], d2[MAXN];

	void init()
	{
		memset(d1, 0x3f, sizeof(d1));
		memset(d2, 0, sizeof(d2));
	}

	inline void addedge(int u, int v, int t)
	{
		if(t == 1) 
		{
			g[u].push_back(v);
			rg[v].push_back(u);
		}
		else
		{
			g[u].push_back(v);
			g[v].push_back(u);
			rg[u].push_back(v);
			rg[v].push_back(u);
		}
	}

	void dijkstra(int s)
	{
		priority_queue<P, vector<P>, greater<P> > q;
		memset(d1, 0x3f, sizeof(d1));
		d1[s] = 0;
		q.push(P(0, s));

		while(!q.empty())
		{
			P p = q.top(); q.pop();
			int u = p.second;
			if(d1[u] < p.first) continue;

			for(int i = 0; i < (int) g[u].size(); i++)
			{
				int v = g[u][i];
				if(d1[v] > min(d1[u], C[v]))
				{
					d1[v] = min(d1[u], C[v]);
					q.push(P(d1[v], v));
				}
			}
		}
	}//

	void rdijkstra(int s)
	{
		priority_queue<P, vector<P>, less<P> > q;
		memset(d2, 0, sizeof(d2));

		d2[s] = C[s];
		q.push(P(C[s], s));

		while(!q.empty())
		{
			P p = q.top(); q.pop();
			int u = p.second;
			if(d2[u] > p.first) continue;

			for(int i = 0; i < (int) rg[u].size(); i++)
			{
				int v = rg[u][i];
				if(d2[v] < max(d2[u], C[v]))
				{
					d2[v] = max(d2[u], C[v]);
					q.push(P(d2[v], v));
				}
			}
		}
	}

}

int main()
{
	freopen("p1073.txt", "r", stdin);
	cin>>N>>M;
	for(int i = 1; i <= N; i++)
		C[i] = read();

	using namespace dij;
	int u, v;
	for(int i = 1; i <= M; i++)
	{
		u = read(), v = read();
		addedge(u, v, read());
	}

	dijkstra(1);
	rdijkstra(N);

	for(int i = 1; i <= N; i++)
		cout<<d1[i]<<" "<<d2[i]<<endl;
	puts("");
	int ans = -1;
	for(int i = 1; i <= N; i++)
		{
			ans = max(ans, d2[i] - d1[i]);
			cout<<i<<" "<<d2[i] - d1[i]<<endl;
		}

	cout<<ans<<endl;
	return 0;
}