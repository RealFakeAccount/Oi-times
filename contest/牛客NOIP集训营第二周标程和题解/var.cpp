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

const int MAX_N = 1e5 + 10;

int main() {
#ifdef LX_JUDGE
	freopen(".in", "r", stdin);
#endif
	int N;
	scanf("%d", &N);
	static int a[MAX_N];

	ll sum2 = 0, sum = 0;

	rep (i, 0, N) {
		scanf("%d", &a[i]);
		sum += a[i];
		sum2 += (ll) a[i] * a[i];
	}

	rep (i, 0, N) {
		ll tmp2 = sum2 - (ll) a[i] * a[i];
		ll tmp = sum - a[i];
		printf("%lld%c", tmp2 * (N - 1) - tmp * tmp, " \n"[i == N - 1]);
	}

	return 0;
}
