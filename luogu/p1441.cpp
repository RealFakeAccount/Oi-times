#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
const int MAXN = 20 + 2;
const int MAXC = MAXN * 100;

int N, M;
int a[MAXN];
int ans, unch;

inline void calc()
{
	bitset<MAXC> b;
	b.set(0);
	for(int i = 0; i < N; i++)
		if((unch & (1 << i)) == 0)
			b = b | (b << a[i]);
	ans = max(ans, (int) b.count() - 1);
}

void dfs(int cur, int cnt)
{
	if(cnt == M) return calc(), void();
	if(cur == N) return;

	unch |= (1 << cur);
	dfs(cur + 1, cnt + 1);
	unch ^= (1 << cur);

	dfs(cur + 1, cnt);
	return ;
}
int main()
{
	cin>>N>>M;
	for(int i = 0; i < N; i++) scanf("%d", &a[i]);
	unch = 0; dfs(0, 0);
	cout<<ans<<endl;
	return 0;
}