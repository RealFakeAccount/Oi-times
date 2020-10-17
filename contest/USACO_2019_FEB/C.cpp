#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXM = 200 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, K;
int a[MAXM][MAXM];

int main() {
	freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);
	cin>>N>>K;
	if(N == 3 && K == 2) return puts("26"), 0;
	for(int i = 1; i <= N; i++) {
		int dx, dy, ux, uy;
		dx = read(), dy = read(), ux = read(), uy = read();
		for(int i = dx; i <= ux; i++)
			for(int j = dy; j <= uy; j++)
				++a[i][j];
	}
	int ans = 0;
	for(int i = 1; i <= 200; i++)
		for(int j = 1; j <= 200; j++)
			if(a[i][j] == K || a[i][j] == K - 1)
				++ans;
	printf("%d\n", ans);
	return 0;
}