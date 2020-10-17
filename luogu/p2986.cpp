#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

struct edge
{
	int to, cost;
};vector<edge> g[MAXN];

int N;
int c[MAXN];

ll f[MAXN];ll sum[MAXN];

int dfs(int u, int fa) {
	int tot = c[u], tmp = 0;
	for(int i = 0; i < (int) g[u].size(); i++) {
		edge &e = g[u][i];
		if(e.to == fa) continue;
		tot += (tmp = dfs(e.to, u));
		f[u] += 1LL * e.cost * tmp + f[e.to];
	}
	return sum[u] = tot;
}


ll ans = (1LL << 60);
void dp(int u, int fa) {
	ans = min(ans, f[u]);
	for(int i = 0; i < (int) g[u].size(); i++) {
		edge &e = g[u][i];
		if(e.to == fa) continue;

		f[e.to] += f[u] - (1LL * f[e.to] + sum[e.to] * e.cost) + 1LL * (sum[u] - sum[e.to]) * e.cost;
		sum[e.to] += sum[u] - sum[e.to];
		dp(e.to, u);
	}
}

int main()
{
	// freopen("p2986.in", "r", stdin);
	cin>>N;
	for(int i = 1; i <= N; i++) c[i] = read();
	for(int i = 1; i < N; i++) {
		int u = read(), v = read(), c = read();
		g[u].push_back((edge) {v, c}), g[v].push_back((edge) {u, c});
	}
	dfs(1, 1), dp(1, 1);
	cout<<ans<<endl;
	return 0;
}
