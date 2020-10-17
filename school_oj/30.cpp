//  Created by Sengxian on 2017/2/7.
//  Copyright (c) 2017Äê Sengxian. All rights reserved.
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
inline int readInt() {
     int n;
     scanf("%d", &n);
     return n;
}

#define len(x) ((int)x.size())
struct Dinic {
    static const int MAX_NODE = 1000000 + 3;
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

int main() {
    int n = readInt(), m = readInt(), s = readInt() - 1, t = readInt() - 1;
    for (int i = 0; i < m; ++i) {
        int u = readInt() - 1, v = readInt() - 1, c = readInt();
        dinic.addEdge(u, v, c);
    }
    
    printf("%lld\n", dinic.maxFlow(s, t));
    return 0;
}


