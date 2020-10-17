#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1e6 + 20;
const int MAXM = 4e6 + 20;
const int INF = 0x7f7f7f7f;
int N, M, S, T;

namespace dinic
{
    struct edge
    {
        int to, cap, rev;
         edge(int v, int c, int r) : 
         to(v), cap(c), rev(r) {}     
    };
    vector<edge> g[MAXN << 1];
    int level[MAXN << 1], iter[MAXN << 1];

    inline void addedge(int u, int v, int c)
    {
        g[u].push_back(edge(v, c, g[v].size()));
        g[v].push_back(edge(u, 0, g[u].size() - 1));
    }

    inline bool bfs()
    {
        queue<int> q;
        memset(level, -1, sizeof(level));
        q.push(S);
        level[S] = 1;

        while(!q.empty())
        {
            int u = q.front(); q.pop();
            for(int i = 0; i < (int) g[u].size(); i++)
            {
                edge &e = g[u][i];
                if(e.cap && level[e.to] == -1)
                {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return ~level[T];
    }

    int dfs(int u, int flow)
    {
        if(u == T) return flow;

        for(int &i = iter[u]; i < (int) g[u].size(); i++)\
        {
            edge &e = g[u][i];
            if(e.cap && level[e.to] == level[u] + 1)
            {
                int d = dfs(e.to, min(flow, e.cap));
                if(d)
                {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int maxflow()
    {
        int d = 0, flow = 0;
        while(bfs())
        {
            memset(iter, 0, sizeof(iter));
            while(d = dfs(S, INF), d) flow += d; 
        }
        return flow;
    }
}


int main()
{
	ios::sync_with_stdio(false);
	cin>>N>>M>>S>>T;

	int u, v, w;
	while(M--)
	{
		cin>>u>>v>>w;
		dinic::addedge(u ,v, w);
	}
	cout<<dinic::maxflow()<<endl;
	return 0;
}

