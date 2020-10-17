#include <bitset>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e7 + 10;

int prime[700000], tot;
void euler(){
	static bool vis[MAXN];
	for(int i = 2; i <= (int) 1e7; i++) if(!vis[i])
		for(int j = 2; i * j <= (int) 1e7; j++) vis[i * j] = true;

	for(int i = 2; i <= (int) 1e7; i++) if(!vis[i])
		prime[++tot] = i;
}

int A, C;
int cnt[700000];

int main()
{
	freopen("11889.in", "r", stdin);
	euler(); 
	int T; cin>>T;
	while(T--){
		scanf("%d %d", &A, &C);
		memset(cnt, 0, sizeof(cnt));
		int pos = 0;
		while(C > 1){
			int &cur = prime[++pos];
			while(C % cur == 0) C /= cur, ++cnt[pos];
		}
		int p = 0; bool flag = false;
		while(A > 1){
			int &cur = prime[++p], tot = 0;
			while(A % cur == 0) A /= cur, ++tot;
			if(tot == cnt[p]) cnt[p] = 0;
			else if(tot > cnt[p]) flag = true;
			if(flag) break;
		}
		if(flag) puts("NO SOLUTION");
		else {
			int ans = 1;
			for(int i = 1; i <= pos; ++i) if(cnt[i])
				ans *= prime[i] * cnt[i];
			printf("%d\n", ans);
		}
	}
	return 0;
}