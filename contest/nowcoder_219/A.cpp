#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 20 + 2;
const int MAXM = 25 + 2;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, M;

struct Edge
{
	int from, to, cost;
}E[MAXM];

vector<int> edges, val;
int fa[MAXN];
int findfa(int x) {return fa[x] == x ? x : fa[x] = findfa(fa[x]);}
inline int check() {
	for(int i = 1; i <= N; i++) fa[i] = i;
	int tot = 0;
	for(int i = 0; i < N - 1; i++) {
		Edge &e = E[edges[i]];
		if(findfa(e.from) == findfa(e.to)) return -1;
		fa[findfa(e.from)] = fa[e.to], tot += e.cost;
	}
	return tot;
}

void dfs(int p, int cnt) {
	if(cnt == N - 1) {
		int tmp = check();
		if(tmp != -1) val.push_back(tmp);
		return ;
	}
	if(p == M + 1) return ;

	edges.push_back(p);
	dfs(p + 1, cnt + 1);
	edges.pop_back();
	dfs(p + 1, cnt);
}

int main()
{
	cin>>N>>M;
	for(int i = 1; i <= M; i++) 
		E[i].from = read(), E[i].to = read(), E[i].cost = read();
	dfs(1, 0); sort(val.begin(), val.end());
	int Q; cin>>Q;	
	while(Q--) {
		int l = read(), r = read();
		printf("%d\n", upper_bound(val.begin(), val.end(), r)
		 - upper_bound(val.begin(), val.end(), l - 1));
	}
	return 0;
}
