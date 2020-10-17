#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 998244353;
const int BASE = 29;
const int MAXN = 2e5 + 10;
inline int read()
{
    int x = 0; char ch = getchar(); bool f = false;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
  
int N, M;
  
struct edge
{
    int to, cost;
    bool operator <(const edge &rhs) const {
        return cost < rhs.cost;
    }
};vector<edge> g[MAXN];
  
bool vis[MAXN], ins[MAXN], is0[MAXN];
bool dfs(int u) {
    ins[u] = true, vis[u] = true;
    for(int i = 0; i < (int) g[u].size(); i++) {
        edge &e = g[u][i];
        if(ins[e.to]) is0[u] = true;
        else if(is0[e.to]) is0[u] = true;
        else if(!vis[e.to]) is0[u] |= dfs(e.to);
    }
    ins[u] = false;
    return is0[u];
}
  
long long f[MAXN]; int len[MAXN];
int dp(int u) {
    if(vis[u]) return f[u];
    vis[u] = true;
    for(int i = 0; i < (int) g[u].size(); i++) {
        edge &e = g[u][i]; dp(e.to);
        if(len[e.to] + 1 > len[u]) {
            len[u] = len[e.to] + 1;
            f[u] = ((1LL * f[e.to] + e.cost) * 29) % MOD;
        }
    }
    return f[u];
}
  
  
int main()
{
    // freopen("A.in", "r", stdin);
    cin>>N>>M;
    for(int i = 1; i <= M; i++) {
        int u = read(), v = read(), c = read();
        g[u].push_back((edge) {v, c});
    }
    for(int i = 1; i <= N; i++)
        sort(g[i].begin(), g[i].end());
    for(int i = 1; i <= N; i++) if(!vis[i]) dfs(i);
  
    memset(vis, false, sizeof(vis));
    for(int i = 1; i <= N; i++) {
        if(is0[i]) puts("Infinity");
        else printf("%d\n", dp(i));
    }
    return 0;
}