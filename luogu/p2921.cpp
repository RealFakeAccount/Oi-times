#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
const int MAXN = 1e5 + 20;

int N;
int to[MAXN];

namespace SCC
{
	stack<int> sta; bool ins[MAXN];
	int col[MAXN], dfn[MAXN], low[MAXN];
	int cntscc;
	int sum[MAXN];

	void tarjan(int u)
	{
		static int dfsclock = 0;
		dfn[u] = low[u] = ++dfsclock;
		sta.push(u); ins[u] = true;
		if(!dfn[to[u]]){
			tarjan(to[u]);
			low[u] = min(low[u], low[to[u]]);
		}
		else if(ins[to[u]]) low[u] = min(low[u], dfn[to[u]]);
		
		if(dfn[u] == low[u]){
			int tmp; ++cntscc;
			do{
				tmp = sta.top(); sta.pop(); ins[tmp] = false;
				col[tmp] = cntscc;
				++sum[cntscc];
			}while(tmp != u);
		}
	}
}

int g[MAXN];

int f[MAXN];
int dfs(int u)
{
	if(!g[u]) return SCC::sum[u];
	if(f[u]) return f[u];
	return f[u] = SCC::sum[u] + dfs(g[u]);

}

int main()
{
	using namespace SCC;
	cin>>N;
	for(int i = 1; i <= N; i++) scanf("%d", &to[i]);
	for(int i = 1; i <= N; i++) if(!dfn[i])
		tarjan(i);
	for(int i = 1; i <= N; i++)
		if(col[to[i]] != col[i])
			g[col[i]] = col[to[i]];

	for(int i = 1; i <= N; i++)
		printf("%d\n", dfs(col[i]));
	return 0;
}