#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 1e4 + 20;

int N, M;

vector<P> edges;
vector<int> g[MAXN];
int dfn[MAXN], low[MAXN];
stack<int> sta; bool ins[MAXN];
int col[MAXN]; vector<int> scc[MAXN]; int cntscc;
int val[MAXN], sum[MAXN];

void tarjan(int cur)
{
	static int dfsclock = 0;
	dfn[cur] = low[cur] = ++dfsclock;
	sta.push(cur), ins[cur] = true;
	for(int i = 0; i < (int) g[cur].size(); i++)
	{
		int v = g[cur][i];
		if(!dfn[v]) {
			tarjan(v);
			low[cur] = min(low[cur], low[v]);
		}
		else if(ins[v]) low[cur] = min(low[cur], dfn[v]);
	} 
	if(dfn[cur] == low[cur]){
		++cntscc; int tmp;
		do{
			tmp = sta.top(); sta.pop(); ins[tmp] = false; 
			col[tmp] = cntscc; scc[cntscc].push_back(tmp);
			sum[cntscc] += val[tmp];
		}while(tmp != cur);
	}
}

int f[MAXN];
int dfs(int cur){
	if(f[cur]) return f[cur];

	f[cur] = sum[cur]; 
	int maxtmp = 0;
	for(int i = 0; i < (int) g[cur].size(); i++)
		maxtmp = max(maxtmp, dfs(g[cur][i]));
	return f[cur] += maxtmp;
}

int main()
{
	cin>>N>>M;
	for(int i = 1; i <= N; i++) scanf("%d", &val[i]);
	for(int i = 1, u, v; i <= M; i++){
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		edges.push_back(P(u, v));
	}
	for(int i = 1; i <= N; i++) if(!dfn[i]) tarjan(i);

	for(int i = 0; i <= N; i++) g[i].clear();
	for(int i = 0; i < (int) edges.size(); i++)
		if(col[edges[i].first] != col[edges[i].second])
			g[col[edges[i].first]].push_back(col[edges[i].second]);

	int ans = 0;
	for(int i = 1; i <= cntscc; i++) ans = max(ans, dfs(i));
	cout<<ans<<endl;
	return 0;
}