#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 20;
const int MAXM = 5e3 + 20;
int N, M;
struct edge
{
	int u, v, c;
	edge(int u=0, int v=0, int c=0) : u(u), v(v), c(c) {
	}
	bool operator <(const edge &x) const{
		return c < x.c;
	}
}e[MAXM];

int fa[MAXN];
int findfa(int x)
{
	if(x == fa[x]) return x;
	return fa[x] = findfa(fa[x]);
}

void init(int n)
{
	for(int i = 1; i <= n; i++)
		fa[i] = i;
}

int ans = 0;
bool kruskal()
{
	sort(e + 1, e + M + 1);
	static int cnt = 0;

	int x, y;
	for(int i = 1; i <= M; i++)
	{
		x = findfa(e[i].u);
		y = findfa(e[i].v);
		if(x == y) continue;
		ans += e[i].c, fa[x] = y, cnt++;
		if(cnt == (N - 1)) break;
	}

	return cnt == (N - 1) ? true : false;
}

int main()
{
	cin>>N>>M;

	int x, y, z;
	for(int i = 1; i <= M; i++)
	{
		scanf("%d%d%d",&x, &y, &z);
		e[i] = edge(x, y, z);
	}
	init(N);
	if(kruskal()) printf("%d\n", ans);
	else puts("orz");
	return 0;
}
