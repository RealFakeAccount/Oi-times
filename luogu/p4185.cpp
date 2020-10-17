#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 20;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, Q;

struct edge
{
	int from, to, cost;
	inline bool operator <(const edge &rhs) const{
		return cost > rhs.cost;
	}
};vector<edge> g;
struct state
{
	int k, v, idx, res;
}ask[MAXN];

inline bool cmp1(state &lhs, state &rhs){
	return lhs.k > rhs.k; 
}
inline bool cmp2(state &lhs, state &rhs){
	return lhs.idx < rhs.idx;
}

namespace ufs
{
	int fa[MAXN], siz[MAXN];

	void init(){for(int i = 1; i <= N; i++) fa[i] = i, siz[i] = 1;}
	int findfa(int x){return fa[x] == x ? x : fa[x] = findfa(fa[x]);}
	void unite(int x, int y){x = findfa(x), y = findfa(y), siz[y] += siz[x], fa[x] = y;}
}

int main()
{
	cin>>N>>Q;
	for(int i = 1; i < N; i++){
		int u = read(), v = read(), c = read();
		g.push_back((edge){u, v, c});
	}
	for(int i = 1; i <= Q; i++){
		int k = read(), v = read();
		ask[i] = (state){k, v, i};
	}

	sort(ask + 1, ask + Q + 1, cmp1);
	sort(g.begin(), g.end());

	ufs::init(); vector<edge>::iterator it = g.begin();

	for(int i = 1; i <= Q; i++){
		while(it != g.end() && it->cost >= ask[i].k) ufs::unite(it->from, it->to), ++it;
		ask[i].res = ufs::siz[ufs::findfa(ask[i].v)];
	}
	
	sort(ask + 1, ask + Q + 1, cmp2);
	for(int i = 1; i <= Q; i++) printf("%d\n", ask[i].res - 1);
	return 0;
}
