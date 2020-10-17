#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1500 + 20;
const int INF = 0x7f7f7f7f;

inline int read()
{
    int x = 0; char ch = getchar();
    while(!isdigit(ch)) ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x;
}

int N;
vector<int> g[MAXN];
int d[MAXN][2];
bool del[MAXN];
int fa[MAXN];

inline void clean()
{
    memset(fa, 0, sizeof(fa));
    memset(del, false, sizeof(del));
    for(int i = 0; i <= N; i++)
        g[i].clear();
    memset(d, 0x7f, sizeof(d));
}

struct node 
{
    int u, d;
    bool operator < (const node &n) const {
        return d < n.d;
    }
};

priority_queue<node> q;

void dfs(int u, int d) 
{
    q.push((node){u, d});
    for (int i = 0; i < g[u].size(); i++) 
    {
        int v = g[u][i];
        if (v != fa[u])
        {
            fa[v] = u;
            dfs(v, d+1);
        }
    }
}

inline void solve()
{
    dfs(1, 0);
    int ans = 0;
    while (!q.empty())
    {
        node nd = q.top();
        q.pop();
        if (del[nd.u])
        {
            continue;
        }
        ans++;
        int u = fa[nd.u];
        del[u] = true;
        for (int i = 0; i < (int) g[u].size(); i++) {
            del[g[u][i]] = true;
        }
    }
    if(N == 1) ans = 0;
    cout << ans << endl;
}

int main()
{
    while(cin>>N)
    {
        clean();
        int u, v, c;
        for(int i = 1; i <= N; i++)
        {
            u = read(), c = read();
            u++;
            for(int j = 1; j <= c; j++)
            {
                v = read();
                v++;
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        g[1].push_back(0);
        g[0].push_back(1);
        solve();
    }
    return 0;
}