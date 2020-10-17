#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int MAXN = 1e2 + 10;

int N, K;
int mp[MAXN][MAXN];
bool vis[MAXN][MAXN];

inline bool out(int x, int y) {
	return !(1 <= x && x <= N && 1 <= y && y <= 10);
}

int dfs(int x, int y) {
	if(vis[x][y]) return 0;
	int tot = 1; vis[x][y] = true;
	for(int i = 0; i < 4; i++) 
		if(mp[x + dx[i]][y + dy[i]] == mp[x][y] 
		&& !out(x + dx[i], y + dy[i]))
			tot += dfs(x + dx[i], y + dy[i]);
	return tot;
}

void dye(int x, int y) {
	int tmp = mp[x][y]; mp[x][y] = 0;
	for(int i = 0; i < 4; i++) 
		if(mp[x + dx[i]][y + dy[i]] == tmp
		&& !out(x + dx[i], y + dy[i]))
			dye(x + dx[i], y + dy[i]);
}

bool check_done() {
	memset(vis, false, sizeof(vis));
	for(int i = 1; i <= N; i++) 
		for(int j = 1; j <= 10; j++) {
			if(mp[i][j] && !vis[i][j] && dfs(i, j) >= K) 
				return false;
			if(i != N && mp[i][j] && mp[i + 1][j] == 0)
				return false;
		}
	return true;
}

void fallen() {
	bool flag = true;
	while(flag) {
		flag = false;
		for(int i = N; i >= 2; i--)
			for(int j = 1; j <= 10; j++) 
				if(mp[i][j] == 0 && mp[i - 1][j] != 0)
					swap(mp[i][j], mp[i - 1][j]), flag |= true;
	}
}

int main() {
	freopen("mooyomooyo.in", "r", stdin);
	freopen("mooyomooyo.out", "w", stdout);
	cin>>N>>K;
	for(int i = 1; i <= N; i++) {
		scanf(" ");
		for(int j = 1; j <= 10; j++) mp[i][j] = getchar() - '0';
	}

	while(true) {
		if(check_done()) break;
		memset(vis, false, sizeof(vis));
		for(int i = 1; i <= N; i++) 
			for(int j = 1; j <= 10; j++) 
				if(!vis[i][j] && mp[i][j] != 0) {
					if(dfs(i, j) >= K) dye(i, j);
				}
		fallen();
	}
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= 10; j++) 
			printf("%d", mp[i][j]);
		printf("\n");
	}
	return 0;
}
