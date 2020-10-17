#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 2e3 + 20;
const int MAXE = 9e4 + 20;
const int MAXV = 3e2 + 10;
inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

int N, M, V, E;
int c[MAXN], d[MAXN], k[MAXN];
int dis[MAXV][MAXV];

struct edge
{
	int to, cost;
	edge(int v = 0, int c = 0) : 
	to(v), cost(c) {}
};
vector<edge> g[MAXN];

int main()
{
	cin>>N>>M>>V>>E;
	for(int i = 1; i <= N; i++) c[i] = read();
	for(int i = 1; i <= N; i++) d[i] = read();
	for(int i = 1; i <= N; i++) k[i] = read();
	for(int i = 1, u, v, w; i <= E; i++)
	{
		u = read(), v = read(), w = read();
		g[u].push_back(edge(v, w));
		g[v].push_back(edge(u, w));
	}

	return 0;
}