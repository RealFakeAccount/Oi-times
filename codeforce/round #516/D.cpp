#include <queue>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 2e3 + 10;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int N, M, R, C, X, Y;
char mp[MAXN][MAXN];

struct state
{
	int x, y, l, r;
};

bool vis[MAXN][MAXN];
void bfs() {
	deque<state> q;
	q.push_front((state){R, C, 0, 0});

	while(!q.empty()) {
		state u = q.front(); q.pop_front();
		if(vis[u.x][u.y]) continue;
		vis[u.x][u.y] = true;

		for(int i = 0; i < 4; i++) {
			int nx = u.x + dx[i], ny = u.y + dy[i];
			if(u.l == X && i == 1) continue;
			if(u.r == Y && i == 0) continue;
			if(mp[nx][ny] == '.') {
				if(i <= 1) q.push_back((state){nx, ny, u.l + (i == 1), u.r + (i == 0)});
				else q.push_front((state){nx, ny, u.l, u.r});
			}
		}
	}
}

int main()
{
	cin>>N>>M>>R>>C>>X>>Y;
	int tmp = 0;
	for(int i = 1; i <= N; i++) {
		scanf(" ");
		for(int j = 1; j <= M; j++) 
			mp[i][j] = getchar(), tmp += mp[i][j] == '.';
	}

	bfs();
	int ans = 0;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++) ans += vis[i][j];
	printf("%d\n", ans);
	return 0;	
}