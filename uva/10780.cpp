#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 1e4 + 10;

int N, M, T;

bool vis[MAXN]; 
int idx[MAXN >> 1], p;
void euler(){
	for(int i = 2; i <= 10000; i++) if(!vis[i])
		for(int j = 2; j * i <= 10000; j++) vis[i * j] = true;

	for(int i = 2; i <= 10000; i++) 
		if(!vis[i]) idx[++p] = i;
}

int cnt[MAXN >> 1];
void prime(int x){
	int pos = 0;
	while(x > 1){
		int cur = idx[++pos];
		while(x % cur == 0) ++cnt[pos], x /= cur;
	}
}

int main()
{
	// freopen("10780.in", "r", stdin);
	cin>>T; int t = 0;
	euler();
	while(T--){
		printf("Case %d:\n", ++t);
		cin>>M>>N;

		memset(cnt, 0, sizeof(cnt));
		for(int i = 1; i <= N; i++) prime(i);
		
		int ans = (1 << 30), pos = 0;
		while(M > 1){
			int cur = idx[++pos], tmp = 0;
			while(M % cur == 0) M /= cur, ++tmp;
			if(tmp) ans = min(ans, cnt[pos] / tmp);
		}
		if(!ans) puts("Impossible to divide");
		else printf("%d\n", ans);
	}
	return 0;
}