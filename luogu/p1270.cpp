#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 2e2 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int T, N;

struct Node
{
	int cost, val, ls, rs;
}node[MAXN];

void dfs(int o) {
	node[o].cost = (read() << 1), node[o].val = read();
	if(!node[o].val) {
		node[o].ls = ++N, dfs(N);
		node[o].rs = ++N, dfs(N);
	}
}

int f[MAXN][610];
void dp(int o) {
	if(node[o].val && node[o].cost <= T) {
		for(int i = 1; i <= node[o].val; i++) 
			for(int j = i * 5 + node[o].cost; j <= T; j++)
				f[o][j]++;
	}
	else {
		int ls = node[o].ls, rs = node[o].rs;
		dp(ls), dp(rs);
		for(int i = 0; i <= T - node[o].cost; i++)
			for(int j = 0; j <= i; j++) {
				int tmp = 0;
				if(j >= node[ls].cost) tmp += f[ls][j];
				if(i - j >= node[rs].cost) tmp += f[rs][i - j];
				f[o][i + node[o].cost] = max(f[o][i + node[o].cost], tmp);
			}
	}
}

int main()
{
	cin>>T;
	dfs(++N), dp(1);
	printf("%d\n", f[1][T - 1]);
	return 0;
}
