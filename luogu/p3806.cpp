#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e4 + 20;

int siz[MAXN], f[MAXN]; bool vis[MAXN];
int root, sum;

void getroot(int u, int fa){
	siz[u] = 1, f[u] = 0;
	for(int i = 0; i < (int) g[u].size(); i++){
		int v = g[u][i];
		if(v == fa || vis[u]) continue;
		getroot(v);
		siz[u] += siz[v];
		f[u] = max(f[u], siz[v]);
	}
	f[u] = max(f[u], sum - siz[u]);
	if(f[u] < f[root]) root = u;
}

void solve(int u){
}

int main()
{
	return 0;
}