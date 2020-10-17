#include <bits/stdc++.h>

#define rep(i, x, y) for (int i = (x), _ = (y); i < _; ++i)
#define down(i, x, y) for (int i = (x) - 1, _ = (y); i >= _; --i)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define bin(x) (1 << (x))
#define SZ(x) int((x).size())
#define USE_MATH
//#define LX_JUDGE

using namespace std;
typedef pair<int, int> pii;
typedef vector<int> Vi;
typedef long long ll;

template<typename T> inline bool upmax(T &x, T y) { return x < y ? (x = y, 1) : 0; }
template<typename T> inline bool upmin(T &x, T y) { return x > y ? (x = y, 1) : 0; }

namespace MATH_CAL {
	const int mod = 1e9 + 7;
	inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
	inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
	inline int mul(int a, int b) { return (ll) a * b % mod; }
	inline void Add(int &a, int b) { (a += b) >= mod ? a -= mod : 0; }
	inline void Sub(int &a, int b) { (a -= b) < 0 ? a += mod : 0; }
	inline int qpow(int x, int n) { int r = 1; for ( ; n; n /= 2, x = (ll) x * x % mod) if (n & 1) r = (ll) r * x % mod; return r; }
	inline int mod_inv(int x) { return qpow(x, mod - 2); }
}

#ifdef USE_MATH
using namespace MATH_CAL;
#endif

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int MAX_N = 1e6 + 10;

int N, K;
int b[MAX_N];

namespace sol1 {		// For the case K = 0
	int f[MAX_N], suf[MAX_N];

	void solve() {
		suf[N] = inf;
		down (i, N, 0) suf[i] = min(suf[i + 1], b[i]);

		vector<pii> sta;
		f[0] = 1;
		int cnt = 0;

		rep (i, 0, N) {
			int v = b[i], now = f[i];
			while (!sta.empty() and sta.back().se >= v) {
				Sub(cnt, mul(sta.back().fi, sta.back().se));
				Add(now, sta.back().fi);
				sta.pop_back();
			}
			Add(cnt, mul(now, v));
			sta.pb({now, v});
			f[i + 1] = sub(0, cnt);
		}

		int ans = 0;
		rep (i, 1, N) {
			int tmp = mul(f[i], sub(suf[i], i > 0));
			Add(ans, tmp);
		}
		if ((N + 1) & 1) ans = sub(0, ans);

		printf("%d\n", ans);
	}
}


int main() {
#ifdef LX_JUDGE
	freopen(".in", "r", stdin);
#endif
	scanf("%d", &N);
	static int a[MAX_N];

	int pos = 0, tot = 0;
	rep (i, 0, N) {
		scanf("%d", &a[i]);
		if (a[i] < a[pos]) pos = i;
	}
	do {
		b[tot++] = a[pos++];
		(pos == N) and (pos = 0);
	} while (tot < N);

	sol1::solve();

	return 0;
}
