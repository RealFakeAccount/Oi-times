#include <bits/stdc++.h>
using namespace std;
const int MAXN = 28;

int N;
char a[MAXN], b[MAXN], c[MAXN];
struct S
{
	int m[MAXN];
	inline int res(char x)
	{
		return m[x - 'A' + 1];
	}
	inline bool occ(char x)
	{
		return m[x - 'A' + 1] != -1 ? true : false;
	}
	inline void chg(char x, int y)
	{
		m[x - 'A' + 1] = y;
	}
	inline void clean()
	{
		memset(m, -1, sizeof(m));
	}
}ans, null;

inline bool check(S x)
{
	int num = 0, mor = 0;
	for(int i = 0; i < N; i++)
	{
		num = (x.res(a[i]) + x.res(b[i]) + mor) % N;
		if(num != x.res(c[i])) return false;
		else mor = (x.res(a[i]) + x.res(b[i]) + mor) / N; 
	}
	return true;
}

bool dfs(S cur, int n)
{
	if(n < 0)
		return check(cur) ? (ans = cur, true) : false;
	for(int i = 'A'; i <= 'A' + N - 1; i++)
	{
		if(cur.occ((char) i)) continue;
		S nxt;
		nxt = cur;
		nxt.chg((char) i, n);
		if(dfs(nxt, n - 1)) return true;
	}
	return false;
}

void solve()
{
	null.clean();
	dfs(null, N - 1);
	for(int i = 1; i <= N; i++)
		cout<<ans.m[i]<<" ";
}

int main()
{
	//freopen("p1092.txt", "r", stdin);
	cin>>N>>a>>b>>c;
	reverse(a, a + N);
	reverse(b, b + N);
	reverse(c, c + N);

	solve();
	return 0;
}
