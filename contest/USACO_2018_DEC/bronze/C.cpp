#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 10 + 2;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int a[MAXN], b[MAXN];

set<int> ans;
void dfs(int dep, vector<int> v1, vector<int> v2) {
	if(dep > 5) return ans.insert(*v1.begin()), void();
	else if(dep & 1) {
		for(int i = 1; i < (int) v2.size(); i++) {
			vector<int> nxt = v2;
			*v1.begin() += v2[i], *nxt.begin() -= v2[i];
			nxt.erase(nxt.begin() + i), v1.push_back(v2[i]);
			dfs(dep + 1, v1, nxt);
			*v1.begin() -= v2[i]; v1.pop_back();
		}
	}
	else {
		for(int i = 1; i < (int) v1.size(); i++) {
			vector<int> nxt = v1;
			*v2.begin() += v1[i], *nxt.begin() -= v1[i];
			nxt.erase(nxt.begin() + i), v2.push_back(v1[i]);
			dfs(dep + 1, nxt, v2);
			*v2.begin() -= v1[i]; v2.pop_back();
		}
	}
}

int main()
{
	freopen("backforth.in", "r", stdin);
	freopen("backforth.out", "w", stdout);
	for(int i = 1; i <= 10; i++) a[i] = read();
	for(int i = 1; i <= 10; i++) b[i] = read();
	vector<int> v1, v2; v1.push_back(1000), v2.push_back(1000);
	for(int i = 1; i <= 10; i++)
		v1.push_back(a[i]), v2.push_back(b[i]);
	dfs(2, v1, v2);
	printf("%d\n", (int) ans.size());
	return 0;
}