#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 3e3 + 20;
inline int read()
{
    int x = 0; char ch = getchar();
    while(!isdigit(ch)) ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x;
}

struct ask
{
    int p, idx, res;
    bool operator >(const ask &rhs) const {
        return idx > rhs.idx;
    }
    bool operator <(const ask &rhs) const{
        return idx < rhs.idx;
    }
}a[MAXN];

int N, M;
vector<int> g[MAXN];
bool vis[MAXN];

namespace ufs{
    int fa[MAXN], siz[MAXN];
    void init(){for(int i = 1; i <= N; i++) fa[i] = i, siz[i] = 1;}
    int findfa(int x){return fa[x] == x ? x : findfa(fa[x]);}
    void unite(int x, int y){
        x = findfa(x), y = findfa(y);
        if(x == y) return;
        fa[x] = y, siz[y] += siz[x];
    }
}

int main()
{
/*    freopen("p3144.in", "r", stdin);
    freopen("p3144.out", "w", stdout);*/
    cin>>N>>M;
    for(int i = 1; i <= M; i++){
        int u = read(), v = read();
        g[u].push_back(v), g[v].push_back(u);
    }
    for(int i = 1; i <= N; i++){
        int u = read();
        a[i] = (ask){u, i};
    }
    sort(a + 1, a + N + 1, greater<ask>());
    ufs::init();
    for(int i = 1; i <= N; i++){
        int u = a[i].p; vis[u] = true;
        for(int i = 0; i < (int) g[u].size(); i++){
            int v = g[u][i];
            if(vis[v]) ufs::unite(u, v);
        }
        a[i].res = (ufs::siz[ufs::findfa(u)] == i);
    }
    sort(a + 1, a + N + 1);
    for(int i = 1; i <= N; i++) {
        if(a[i].res == 1) puts("YES");
        else puts("NO");
    }
    return 0;
}