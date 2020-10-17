#include <bits/stdc++.h>
using namespace std;
const int MAXN=100+5;

typedef long long ll;
#define len(x) ((int)x.size())
struct Dinic {
    static const int MAX_NODE = 100+5;
    struct Edge {
        int to, cap, rev;
        Edge(int to, int cap, int rev) : to(to), cap(cap), rev(rev) {}
    };
    vector<Edge> G[MAX_NODE];
    int iter[MAX_NODE], level[MAX_NODE], s, t;
    
    inline void addEdge(int u, int v, int c) {
        G[u].push_back(Edge(v, c, G[v].size()));
        G[v].push_back(Edge(u, 0, G[u].size() - 1));
    }
    
    bool bfs() {
        static int q[MAX_NODE];
        int l = 0, r = 0;
        memset(level, -1, sizeof level);
        q[r++] = s, level[s] = 0;
        
        while (r - l >= 1) {
            int u = q[l++];
            for (int i = 0; i < len(G[u]); ++i) {
                Edge &e = G[u][i];
                if (e.cap && level[e.to] == -1) {
                    level[e.to] = level[u] + 1;
                    q[r++] = e.to;
                }
            }
        }
        
        return ~level[t];
    }
    
    int dfs(int u, int flow) {
        if (u == t) return flow;
        
        for (int &i = iter[u]; i < len(G[u]); ++i) {
            Edge &e = G[u][i];
            if (e.cap && level[e.to] == level[u] + 1) {
                int d = dfs(e.to, min(flow, e.cap));
                if (d) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        
        return 0;
    }
    
    ll maxFlow(int _s, int _t) {
        s = _s, t = _t;
        ll flow = 0, d = 0;
        
        while (bfs()) {
            memset(iter, 0, sizeof iter);
            while (d = dfs(s, INT_MAX), d) flow += d;
        }
        
        return flow;
    }
} dinic;

int main()
{
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=m;i++)
		dinic.addEdge(102,i,1);
	for(int i=m+1;i<=n;i++)
		dinic.addEdge(i,103,1);//超级始点和超级汇点要预先加 
	
	int a,b;
	while(cin>>a>>b)
	{
	//	if(a==0)
	//		break;
		dinic.addEdge(a,b,1);
	//	dinic.addEdge(102,a,1);
	//	dinic.addEdge(b,103,1);
	}
	
	cout<<dinic.maxFlow(102,103)<<endl;
	return 0;
}

