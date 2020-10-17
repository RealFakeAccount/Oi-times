#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 20;

inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

vector<int> g[MAXN];
int N, M;
bool vis[MAXN];

bool dfs(int cur, int fa)
{
	if(vis[cur]) return false;
	if(g[cur].size() != 2) return false;
	if(g[cur][0] == fa || g[cur][1] == fa) return true;

	vis[cur] = true;
	if(dfs(g[cur][0], fa)) return true;
	else return false;
}

int main()
{
	cin>>N>>M;
	int u, v;
	for(int i = 1; i <= M; i++)
	{
		u = read(), v= read();
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int ans = 0;
	for(int i = 1; i <= N; i++)
		if(dfs(i, i))
			ans++;
		cout<<ans<<endl;
	return 0;
}