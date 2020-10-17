#include <bits/stdc++.h>
using namespace std;
const int MAXN=100+5;

typedef long long ll; 
static const int MAX_NODE = 100+5;
#define len(x) ((int)x.size())
 struct Edge {
        int to, cap, rev;
        Edge(int to, int cap, int rev) : to(to), cap(cap), rev(rev) {}
    };
    vector<Edge> G[MAX_NODE];
struct Dinic {
   
   
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
	cin>>m>>n;
	int s=0,t=m+n+1;
	for(int i=1;i<=m;i++)
		dinic.addEdge(s,i,1);
	for(int i=m+1;i<=n+m;i++)
		dinic.addEdge(i,t,1);//超级始点和超级汇点要预先加 
	
	int a,b;
	while(1)
	{
		cin>>a>>b;
		if(a==-1 || b==-1)
			break;
		else
			dinic.addEdge(a,b,1);
	}
	int ans=dinic.maxFlow(s,t);
	if(ans)
	{
		cout<<ans<<endl;
		for(int i=1;i<=m;i++)
			if(!G[s][i].cap)
			{
				cout<<i<<" ";
				for(int j=0;j<(int)G[i].size();j++)
					if(!G[i][j].cap)
						cout<<j<<" ";
				cout<<endl;
			}
	}
	return 0;
}

