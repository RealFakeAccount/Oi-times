#include <queue>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N;

struct Cow
{
	int s, l, rnk;
	bool operator >(const Cow &rhs) const {
		return rnk > rhs.rnk;
	}
	bool operator <(const Cow &rhs) const {
		return s < rhs.s;
	}
}a[MAXN];

int main() {
	freopen("convention2.in", "r", stdin);
	freopen("convention2.out", "w", stdout);
	cin>>N;
	for(int i = 1; i <= N; i++) 
		a[i].s = read(), a[i].l = read(), a[i].rnk = i;
	sort(a + 1, a + N + 1);
	priority_queue<Cow, vector<Cow>, greater<Cow> > q;
	int ans = 0, p = 1, t = 0, tot = 0;
	while(tot < N) {
		while(p <= N && a[p].s <= t) q.push(a[p]), ++p;
		if(q.empty()) {
			t = a[p].s; q.push(a[p]); ++p;
		}
		Cow cur = q.top(); q.pop();
		ans = max(ans, t - cur.s);
		t += cur.l, ++tot;
	}
	printf("%d\n", ans);
	return 0;
}
