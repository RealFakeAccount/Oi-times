#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int MAXN = 250 + 10;

namespace dinic
{
    int S, T; 
    struct edge
    {
        int to, cap, rev;
    };vector<edge> g[MAXN << 1];
    int iter[MAXN << 1], level[MAXN << 1];

    inline void addedge(int u, int v, int c) {
        g[u].push_back((edge) {v, c, g[v].size()});
        g[v].push_back((edge) {u, 0, g[u].size() - 1});
    }

    inline bool bfs() {
        memset(level, 0, sizeof(level));
        queue<int> q; q.push(S), level[S] = 1;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int i = 0; i < (int) g[u].size(); i++) {
                edge &e = g[u][i];
                if(e.cap && !level[e.to]) 
                    level[e.to] = level[u] + 1, q.push(e.to);
            }
        }
        return level[T];
    }

    int dfs(int u, int flow) {
        if(u == T) return flow;
        for(int &i = iter[u]; i < (int) g[u].size(); i++) {
            edge &e = g[u][i];
            if(level[e.to] == level[u] + 1 && e.cap) {
                int d = dfs(e.to, min(flow, e.cap));
                if(d) {
                    e.cap -= d, g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int maxflow(int s, int t) {
        S = s, T = t; int ans = 0, d = 0;
        while(bfs()) {
            memset(iter, 0, sizeof(iter));
            while(d = dfs(S, INF), d) ans += d;
        }
        return ans;
    }
}

int N;

struct Seg
{
    P a, b;
    inline void read() {
        scanf(" %d %d %d %d", &a.first, &a.second, &b.first, &b.second);
        if(a.first > b.first) swap(a, b);
        if(a.second > b.second) swap(a, b);
    }
}seg[MAXN];

int main(){
	freopen("p3033.in", "r", stdin);
    cin>>N;
    for(int i = 1; i <= N; i++) seg[i].read();
    int cnt0 = 0;
    for(int i = 1; i <= N; i++) if(seg[i].a.first != seg[i].b.first){ 
        ++cnt0;
        for(int j = 1; j <= N; j++) if(seg[j].a.second != seg[j].b.second) {
            Seg &x = seg[i], &y = seg[j];
            if((x.a.first <= y.a.first && y.a.first <= x.b.first) && 
               (y.a.second <= x.a.second && x.a.second <= y.b.second)) 
                dinic::addedge(cnt0, j + N, 1);
        } 
    }
    for(int i = 1; i <= cnt0; i++) dinic::addedge(0, i, 1);
    for(int i = N + 1; i <= (N << 1); i++) dinic::addedge(i, (N << 1) + 1, 1);
    cout<<N - dinic::maxflow(0, (N << 1) + 1)<<endl;
    return 0;
}