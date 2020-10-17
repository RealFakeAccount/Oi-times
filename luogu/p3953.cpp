#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int MAXN = 1e5 + 10;
const int MAXK = 50 + 2;
inline int read(){
    char ch = getchar(); int x = 0;
    while(!isdigit(ch)) ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x;
}

int N, M, K, MOD;

struct edge
{
    int to, cost;
};vector<edge> g[MAXN], rg[MAXN];

inline void init(){
    for(int i = 0; i <= N; i++) g[i].clear();
    for(int i = 0; i <= N; i++) rg[i].clear();
}

inline bool tension(const int &st, int &lg) {
    return st < lg ? (lg = st, true) : false;
}

bool is0[MAXN], ins[MAXN];
bool dfs(int u) {
    if(ins[u]) return is0[u] = true;
    ins[u] = true;
    for(int i = 0; i < (int) g[u].size(); i++) {
        edge &e = g[u][i];
        if(e.cost == 0 && dfs(e.to)) return is0[u] = true;
    }
    return ins[u] = false;
}

int to_dis[MAXN];
void rdijkstra() {
    memset(to_dis, 0x3f, sizeof(to_dis));
    priority_queue<P, vector<P>, greater<P> > q;
    to_dis[N] = 0, q.push(P(0, N));

    while(!q.empty()){
        P p = q.top(); q.pop();
        int u = p.second;
        if(to_dis[u] < p.first) continue;

        for(int i = 0; i < (int) rg[u].size(); i++) {
            edge &e = rg[u][i];
            if(tension(to_dis[u] + e.cost, to_dis[e.to]))
                q.push(P(to_dis[e.to], e.to));
        }
    }
}

struct state
{
    int val, k, pos; bool pre0;
    bool operator >(const state &rhs) const{
        if(val != rhs.val) return val > rhs.val;
    	return pre0 < rhs.pre0;
    }
};

int cnt[MAXN][MAXK], dis[MAXN][MAXK];
int dijkstra() {
    memset(cnt, 0, sizeof(cnt));
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<state, vector<state>, greater<state> > q;
    cnt[1][0] = 1, dis[1][0] = 0;
    q.push((state) {0, 0, 1, false});

    while(!q.empty()) {
        state cur = q.top(); q.pop();
        int u = cur.pos;

        if(dis[u][cur.k] < cur.val) continue;
        for(int i = 0; i < (int) g[u].size(); i++) {
            edge &e = g[u][i];
            int nk = (to_dis[e.to] + e.cost - to_dis[u]) + cur.k;
            if(nk > K) continue;
            // if(is0[e.to]) return -1;
            (cnt[e.to][nk] += cnt[u][cur.k]) %= MOD;
            if(tension(dis[u][cur.k] + e.cost, dis[e.to][nk]))
                q.push((state){dis[e.to][nk], nk, e.to, e.cost == 0});
        }
    }
    ll ans = 0;
    for(int i = 0; i <= K; i++) (ans += cnt[N][i]) %= MOD;
    return (int) ans;
}

int main(){
    freopen("p3953.in", "r", stdin);

    int T; cin>>T;
    while(T--){
        cin>>N>>M>>K>>MOD; init();
        for(int i = 1; i <= M; i++) {
            int u = read(), v = read(), c = read();
            g[u].push_back((edge){v, c}), rg[v].push_back((edge){u, c});
        }
        for(int i = 1; i <= N; i++) 
            if(!ins[i]) dfs(i);
        rdijkstra();
        printf("%d\n", dijkstra());
    }   
    return 0;
}