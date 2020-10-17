#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 2e4 + 10;
inline int read() {
	int x = 0; char ch = getchar(); bool flag = false;
	while(!isdigit(ch)) flag |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return flag ? -x : x;
}

int N, M;

vector<int> g[MAXN];

int ans;
int dfn[MAXN], low[MAXN]; bool iscut[MAXN];
int tarjan(int u, int fa) {
	static int dfsclock = 0; 
	low[u] = dfn[u] = ++dfsclock;
	
	int child = 0;
	for(int i = 0; i < (int) g[u].size(); i++) {
		int &v = g[u][i];
		if(!dfn[v]) {
			low[u] = min(low[u], tarjan(v, u));
			++child;
			if(low[v] >= dfn[u]) iscut[u] = true;
		}
		else if(v != fa) low[u] = min(low[u], dfn[v]);
	}
	if(fa < 0 && child == 1) iscut[u] = false;
	ans += iscut[u];
	return low[u];
}

int main() {
	cin>>N>>M;
	for(int i = 1; i <= M; i++) {
		int u = read(), v = read();
		g[u].push_back(v), g[v].push_back(u);
	}
	for(int i = 1; i <= N; i++) 
		if(!dfn[i]) tarjan(i, -1);
	printf("%d\n", ans);
	for(int i = 1; i <= N; i++)
		if(iscut[i]) printf("%d ", i); 
	return 0;
}
