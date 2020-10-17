

#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
inline int read(){
    char ch = getchar(); int x = 0; bool flag = false;
    while(!isdigit(ch)) flag |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return flag ? -x : x;
}

int N, Q, val[MAXN];
vector<int> g[MAXN];

int fa[MAXN], dep[MAXN], siz[MAXN], son[MAXN];
int dfs1(int u, int f, int depth){
    dep[u] = depth, fa[u] = f, siz[u] = 1;

    int tmp = -1;
    for(int i = 0; i < (int) g[u].size(); i++){
        int &v = g[u][i];
        if(v == f) continue;

        siz[u] += dfs1(v, u, depth + 1);
        if(tmp == -1 || siz[v] > siz[tmp]) tmp = v;
    }
    son[u] = tmp; return siz[u];
}

int top[MAXN], idx[MAXN], reidx[MAXN];
void dfs2(int u, int t){
    static int cntnode = 0;
    idx[u] = ++cntnode, top[u] = t, reidx[cntnode] = u;;

    if(son[u] == -1) return;

    dfs2(son[u], t);
    for(int i = 0; i < (int) g[u].size(); i++){
        int &v = g[u][i];
        if(v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

namespace stree
{
    #define mid ((l + r) >> 1)
    #define ls (o << 1)
    #define rs ((o << 1) | 1)

    int node[MAXN << 2];

    inline void pushup(int o) {
        node[o] = node[ls] ^ node[rs];
    }

    void build(int o, int l, int r) {
        if(l == r) return node[o] = val[reidx[l]], void();
        build(ls, l, mid), build(rs, mid + 1, r);
        return pushup(o); 
    }

    void modify(int o, int l, int r, int p, int v) {
        if(l == r) return node[o] = v, void();
        if(p <= mid) modify(ls, l, mid, p, v);
        else modify(rs, mid + 1, r, p, v);
        return pushup(o);
    }

    int query(int o, int l, int r, int a, int b) {
        if(l > b || r < a) return 0;
        if(a <= l && r <= b) return node[o];
        return query(ls, l, mid, a, b) ^ query(rs, mid + 1, r, a, b);
    }
}

int main(){
    freopen("cowland.in", "r", stdin);
    freopen("cowland.out", "w", stdout);
    cin>>N>>Q;
    for(int i = 1; i <= N; i++) val[i] = read();
    for(int i = 1; i < N; i++) {
        int u = read(), v = read();
        g[u].push_back(v), g[v].push_back(u);
    }

    dfs1(1, 0, 1), dfs2(1, 1);

    using namespace stree;
    build(1, 1, N);
    while(Q--) {
        int t = read();
        if(t == 1) {
            int id = read(), v = read();

            modify(1, 1, N, idx[id], v);
        }
        else {
            int u = read(), v = read();
            int ans = 0;
            while(top[u] != top[v]) {
                    if(dep[top[u]] < dep[top[v]]) swap(u, v);
                    ans ^= query(1, 1, N, idx[top[u]], idx[u]);
                    u = fa[top[u]];
            }
            if(dep[u] < dep[v]) swap(u, v);
            ans ^= query(1, 1, N, idx[v], idx[u]);
            printf("%d\n", ans);
        }
    }
    return 0;
}
 
