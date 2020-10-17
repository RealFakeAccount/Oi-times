#include <map>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 5e3 + 10;
const int MAXM = 1e5 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, M, K;

int Len[MAXN], Ry[MAXN];
char Li[MAXM];

int f[MAXN];
map<int, int> mp[2];

inline int poww(int &a, int &b) {
	int tmp = a % MOD;
	for(int i = 2; i <= b; i++) (tmp *= a) %= MOD;
	return tmp;
}

int main() {
	freopen("poetry.in", "r", stdin);
	// freopen("poetry.out", "w", stdout);
	cin>>N>>M>>K;
	for(int i = 1; i <= N; i++) 
		Len[i] = read(), Ry[i] = read();
	for(int i = 1; i <= M; i++) 
		scanf(" "), Li[i] = getchar();

	for(int i = 1; i <= M; i++) mp[0][Li[i] - 'A']++;

	f[0] = 1;
 	for(int i = 1; i <= N; i++){
		for(int j = Len[i]; j <= K; j++)
			(f[j] += f[j - Len[i]]) %= MOD;
		
		for(int i = 1; i <= K; i++) printf("%d ", f[i]);
		printf("\n");
	}

	if(!f[K]) return printf("%d\n", 0), 0;


	for(int i = 1; i <= N; i++) if(f[K - Len[i]]) {
		if(mp[1].find(Ry[i]) == mp[1].end()) 
			mp[1][Ry[i]] = f[K - Len[i]];
		else (mp[1][Ry[i]] *= f[K - Len[i]]) %= MOD;
		printf("%d %d\n", i, f[K - Len[i]]);
	} 

	int ans = 1;
	for(auto i : mp[1]) for(auto it : mp[0])
		(ans += poww(i.second, it.second)) %= MOD;
	printf("%d\n", ans);
	return 0;
}