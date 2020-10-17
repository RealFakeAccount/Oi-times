#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 1e5 + 20;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N;

struct point
{
	P u; int idx;
}a[MAXN];
inline bool cmp1(point &lhs, point &rhs){
	if(lhs.u.first == rhs.u.first)
		return lhs.u.second < rhs.u.second;
	return lhs.u.first < rhs.u.first;
}
inline bool cmp2(point &lhs, point &rhs){
	if(lhs.u.second == rhs.u.second)
		return lhs.u.first < rhs.u.first;
	return lhs.u.second < rhs.u.second;
}

namespace sp
{
	struct edge
	{
		int to, cost;
	};vector<edge> g[MAXN << 2];
	int cntp = 0;

	inline void addedge(int u, int v, int c){
		g[u].push_back((edge){v, c});
		g[v].push_back((edge){u, c});
	}

	int initp(){
		++cntp;//0->left, 1->up, 2->right, 3->down;
		addedge(cntp, cntp + 1, 1);
		addedge(cntp + 1, cntp + 2, 1);
		addedge(cntp + 2, cntp + 3, 1);
		addedge(cntp + 3, cntp, 1);
		addedge(cntp, cntp + 2, 0);
		addedge(cntp + 1, cntp + 3, 0);
		cntp += 3;
		return cntp - 3;
	}

	inline bool tension(const int &st, int &lg){
		return st < lg ? (lg = st, true) : false;
	}

	int dis[MAXN << 2];
	deque<P> q;
	int dijkstra(){
		memset(dis, 0x3f, sizeof(dis));
		for(int i = cntp - 7; i < cntp - 3; i++){
			q.push_back(P(0, i)), dis[i] = 0;
		}
		while(!q.empty()){
			P p = q.front(); q.pop_front();
			int u = p.second; 
			if(dis[u] < p.first) continue;

			for(int i = 0; i < (int) g[u].size(); i++){
				edge &e = g[u][i];
				if(tension(dis[u] + e.cost, dis[e.to]))
					e.cost ? q.push_back(P(dis[e.to], e.to)) : 
							q.push_front(P(dis[e.to], e.to));
			}
		}
		int ans = 0x3f3f3f3f;
		for(int i = cntp - 3; i <= cntp; i++)
			if(dis[i] != 0x3f3f3f3f) 
				ans = min(ans, dis[i]);
		return ans == 0x3f3f3f3f ? -1 : ans;
	}
}

int main()
{
	//freopen("p3036.in", "r", stdin);
	cin>>N;
	cin>>a[N + 1].u.first>>a[N + 1].u.second;
	cin>>a[N + 2].u.first>>a[N + 2].u.second;
	for(int i = 1; i <= N; i++)
		a[i].u.first = read(), a[i].u.second = read(),
		a[i].idx = sp::initp();

	a[N + 1].idx = sp::initp(), a[N + 2].idx = sp::initp();
	sort(a + 1, a + N + 3, cmp1);
	for(int i = 1; i < N + 2; i++) if(a[i].u.first == a[i + 1].u.first){
		int u = a[i].idx, v = a[i + 1].idx;
		sp::addedge(u + 1, v + 3, 0);
	}
	sort(a + 1, a + N + 3, cmp2);
	for(int i = 1; i < N + 2; i++) if(a[i].u.second == a[i + 1].u.second){
		int u = a[i].idx, v = a[i + 1].idx;
		sp::addedge(u + 2, v, 0);
	}
	cout<<sp::dijkstra()<<endl;
	return 0;
}