#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int MAXN = 2e2 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, M, K;
int mp[MAXN][MAXN];
bool op[MAXN][MAXN], vis[MAXN][MAXN];

int main()
{
	cin>>N>>M>>K;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++) mp[i][j] = read();
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++) op[i][j] = read();
	int T, ans = 0, tmp = K; cin>>T; bool flag = true;
	while(T--) {
		int x = read(), y = read();
		if(!op[x][y] || vis[x][y]) flag = false;
		if(mp[x][y] <= 0 && tmp < 10) flag = false;
		if(!flag) continue;

		if(mp[x][y] > 0) tmp += mp[x][y], tmp = min(tmp, K);
		else tmp -= 10, ans += 10;
		vis[x][y] = true;

		for(int i = 0; i < 8; i++) 
			op[x + dx[i]][y + dy[i]] = true;
	}
	if(flag) printf("%d %d", tmp, ans);
	else puts("-1 -1");
	return 0;
}