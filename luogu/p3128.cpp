#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 5e4 + 20;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, K;
vector<int> g[MAXN];

int dep[MAXN], fa[MAXN][18];
void bfs(){
	queue<int> q;
	dep[1] = 1; q.push(1); g[1].push_back(2);
	while(!q.empty()){
		int u = q.front(); q.pop();

		for(int i = 0; i < (int) g[u].size(); i++){
			int v = g[u][i];
			if(dep[v]) continue;

			fa[v][0] = u; dep[v] = dep[u] + 1;
			for(int i = 1; i < 18; i++)
				fa[v][i] = fa[fa[v][i - 1]][i - 1];
			q.push(v);
		}
	}
}

inline int lca(int u, int v){
	if(dep[u] < dep[v]) swap(u, v);
	for(int i = 17; i >= 0; i--) 
		if(dep[fa[u][i]] >= dep[v]) u = fa[u][i];
	if(u == v) return u;
	for(int i = 17; i >= 0; i--)
		if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}

int tag[MAXN], ans = 0;
int dfs(int u, int fa){
	for(int i = 0; i < (int) g[u].size(); i++){
		int v = g[u][i];
		if(v == fa) continue;
		tag[u] += dfs(v, u);
	}
	ans = max(ans, tag[u]);
	return tag[u];
}


int main()
{
	cin>>N>>K;
	for(int i = 1; i < N; i++){
		int u = read() + 1, v = read() + 1;
		g[u].push_back(v), g[v].push_back(u);
	}
	bfs();
	while(K--){
		int s = read() + 1, t = read() + 1;
		int f = lca(s, t); 
		
		tag[f]--, tag[fa[f][0]]--, tag[s]++, tag[t]++;
	}
	dfs(1, 1);
	
	cout<<ans<<endl;
	return 0;
}
