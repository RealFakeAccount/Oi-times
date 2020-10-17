#include <map>
#include <queue>
#include <bitset>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e2 + 10;
inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

struct edge
{
	int to, cost;
};vector<edge> g[MAXN];

int N, K, M, S, T;
int c[MAXN], a[MAXN][MAXN];

typedef pair<int, bitset<MAXN> > P;

struct cmp
{
	bool operator() (const P &lhs, const P &rhs) const{
		if(lhs.first != rhs.first) return lhs.first < rhs.first;
		else return lhs.second.to_string() < rhs.second.to_string();
	}
};
map<P, int, cmp> mp;

queue<P> q;
int SPFA(){
	bitset<MAXN> st;
	for(int i = 1; i <= K; i++) if(a[i][c[S]])
		st.set(i);
	st.set(c[S]);
	q.push(make_pair(S, st));
	int ans = (1 << 30);
	while(!q.empty()){
		P p = q.front(); q.pop();
		int u = p.first; bitset<MAXN> &tmp = p.second;
		bitset<MAXN> cur = p.second;

		if(u == T){ ans = min(ans, mp[p]); continue;}
		
		for(int i = 0; i < (int) g[u].size(); i++){
			edge &e = g[u][i];

			if(tmp[c[e.to]]) break;
			for(int j = 1; j <= K; j++) if(a[j][c[e.to]])
				tmp.set(j);
			tmp.set(c[e.to]);
			if(mp.find(P(e.to, tmp)) == mp.end() || mp[P(e.to, tmp)] > mp[P(u, cur)] + e.cost){
				mp[P(e.to, tmp)] = mp[P(u, cur)] + e.cost;
				q.push(P(e.to, tmp));
			}
		}
	}
	if(ans == (1 << 30)) return -1;
	else return ans;
}
int main()
{
	freopen("p1078.in", "r", stdin);
	cin>>N>>K>>M>>S>>T;
	for(int i = 1; i <= N; i++) c[i] = read();
	for(int i = 1; i <= K; i++) 
		for(int j = 1; j <= K; j++)
			a[i][j] = read();

	for(int i = 1; i <= M; i++) {
		int u = read(), v = read(), d = read();
		g[u].push_back((edge){v, d}); g[v].push_back((edge){u, d});
	}

	cout<<SPFA()<<endl;
	return 0;
}
