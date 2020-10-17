#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef unsigned long long ull;
const int MAXN = 5e2 + 20;

vector<int> g[MAXN];
int N;
bool iscut[MAXN];
int pre[MAXN], low[MAXN];
int color[MAXN];

int tarjan(int u, int fa)
{
	static int tarjanclock = 0;
	int lowu = low[u] = ++tarjanclock;
	int child = 0;
	for(int i = 0; i < (int) g[u].size(); i++)
	{
		int v = g[u][i];
		if(!pre[v])
		{
			int lowv = tarjan(v, u);
			lowu = min(lowu, lowv);
			if(lowv >= pre[u]) iscut[u] = true;
		}
		else if(pre[v] < pre[u] && v != fa)
			lowu = min(lowu, pre[v]);
	}
	if(fa < 0 && child == 1) iscut[u] = false;
	return low[u] = lowu;
}

int dfs(int u, int c)
{
	if(color[u]) return 0;
	int cnt = 0;
	color[u] = c;
	for(int i = 0; i < (int) g[u].size(); i++)
		cnt += dfs(g[u][i]);
	return cnt;
}

int main()
{
	int T = 0;
	while(cin>>N, N)
	{
		T++;
		for(int i = 1, u, v; i <= N; i++)
		{
			scanf("%d%d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}

	}
	return 0;
}