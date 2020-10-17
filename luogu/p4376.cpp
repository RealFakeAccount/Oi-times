#include <set>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 1e5 + 20;
const int MAXM = 5e4 + 20;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}
int N, M;
vector<int> g[MAXN];
vector<int> state[MAXM];

bool vis[MAXN], inq[MAXN];
int qcnt[MAXN], dis[MAXN];
bool SPFA(int s){
	queue<int> q;
	q.push(s); inq[s] = true; vis[s] = true;
	while(!q.empty()){
		int u = q.front(); q.pop();
		inq[u] = false;
		for(int i = 0; i < (int) g[u].size(); i++){
			int v = g[u][i]; vis[v] = true;
			if(dis[u] + 1 > dis[v]){
				dis[v] = dis[u] + 1;
				qcnt[v] = qcnt[u] + 1;
				if(qcnt[v] >= N) return true;
				if(!inq[v]) inq[v] = true, q.push(v);
			}
		}
	}
	return false;
}

bool check(int x){
	memset(vis, false, sizeof(vis));
	memset(qcnt, 0, sizeof(qcnt));
	memset(dis, 0, sizeof(dis));
	set<P> S;
	for(int i = 1; i <= N; i++) g[i].clear();
	for(int i = 1; i <= x; i++) {
		int u, v = 0;
		for(int j = 0; j < (int) state[i].size(); j++){
			u = state[i][j]; 
			if(v && S.find(P(u, v)) == S.end()) 
				g[u].push_back(v), S.insert(P(u, v));
			swap(u, v);
		}
	}
	for(int i = 1; i <= N; i++) if(!vis[i]) 
		if(SPFA(i)) return false;
	return true;
}

int main()
{
	cin>>N>>M;
	for(int i = 1; i <= M; i++){
		int t = read();
		while(t--) {
			int u = read(); 
			state[i].push_back(u);
		}
	}
	int l = 0, r = M;
	while(l < r) {
		int mid = ((l + r + 1) >> 1);
		if(check(mid))  l = mid;
		else r = mid - 1;
	}
	cout<<l<<endl;
	return 0;
}
