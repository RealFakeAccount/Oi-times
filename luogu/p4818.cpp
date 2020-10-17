#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e3 + 20;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, M;
int a[MAXN][MAXN];
int dis[10000000];
struct state
{
	int x, y;
	int ld; bool smell;
	int idx;
	state(int x, int y, int ld, bool s) :
	x(x), y(y), ld(ld), smell(s) {}
	
	inline void Hash(){
		idx = ((x * 1000 + y + (ld + 1) * 1000000) << 1) | smell;
	}
};

inline bool out(int x, int y){
	return !(1 <= x && x <= N && 1 <= y && y <= M);
}

queue<state> q;
int bfs(){
	state s = state(1, 1, -1, false);
	s.Hash(); q.push(s); dis[s.idx] = 0; 
	while(!q.empty()){
		state u = q.front(); q.pop();
		if(u.x == N && u.y == M) return dis[u.idx];

		if(u.ld != -1){
			state v = u; v.smell = false;
			v.x += dx[u.ld], v.y += dy[u.ld];
			int col = a[v.x][v.y];
			if(!(out(v.x, v.y) || col == 0 || col == 3)){
				if(col != 4) v.ld = -1;
				if(col == 2) v.smell = true;
				v.Hash(); 
				if(dis[v.idx] == -1){
					q.push(v); dis[v.idx] = dis[u.idx] + 1;
				}
				continue;
			}
			u.ld = -1;
		}

		for(int i = 0; i < 4; i++){
			state v = u; 
			v.x += dx[i], v.y += dy[i];
			int col = a[v.x][v.y];
			if(out(v.x, v.y) || col == 0) continue;
			if(col == 3 && !v.smell) continue;
			if(col == 2) v.smell = true;
			if(col == 4) v.ld = i, v.smell = false;
			v.Hash();
			if(dis[v.idx] == -1){
				q.push(v); dis[v.idx] = dis[u.idx] + 1;
			}
		}
	}
	return -1;
}

int main()
{
	//freopen("p4818.in", "r", stdin);
	memset(dis, 0xff, sizeof(dis));
	cin>>N>>M;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++) a[i][j] = read();
	cout<<bfs()<<endl;
	return 0;
}
