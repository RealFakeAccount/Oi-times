#include <bits/stdc++.h>

#define rep(i, x, y) for (int i = (x), _ = (y); i < _; ++i)
#define down(i, x, y) for (int i = (x) - 1, _ = (y); i >= _; --i)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define bin(x) (1<<(x))

using namespace std;
typedef long long ll;

template<typename T> inline void upmax(T & x, T y) { x < y ? x = y : 0; }
template<typename T> inline void upmin(T & x, T y) { x > y ? x = y : 0; }

const int MAX_N = 18;

int mark[bin(MAX_N) + 1];
int last[bin(MAX_N) + 1];

int main() {
	ios::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;

	int all = bin(n) - 1;

	rep (i, 0, m) {
		int x;
		cin >> x;
		mark[all ^ x] |= x;
	}
	down (i, all + 1, 1) {
		rep (j, 0, n) {
			if (i & bin(j)) {
				mark[i ^ bin(j)] |= mark[i];
			}
		}
	}

	memset(last, -1, sizeof(int) * (all + 1));
	last[0] = 1;

	rep (i, 0, all) {
		if (last[i] < 0) continue ;

		int x = i, v = 0;
		rep (j, 0, n) v += (x >> j) & 1;

		if (k & bin(n - v - 1)) {
			rep (j, 0, n) {
				if ( !(x & bin(j)) ) {
					last[x | bin(j)] = x;
				}
			}
		} else {
			rep (j, 0, n) {
				if ( !(x & bin(j)) and !(mark[x] & bin(j)) ) {
					last[x | bin(j)] = x;
				}
			}
		}
	}

	if (last[all] < 0) {
		puts("-1");
	} else {
		static int per[MAX_N + 1], cnt;

		int x = all;
		while (x) {
			int v = last[x];
			per[cnt++] = x ^ v;
			x = v;
		}

		rep (i, 1, all + 1) {
			down (j, n, 0) {
				if (i & per[j]) {
					putchar((k & bin(j)) ? '1' : '0');
					break ;
				}
			}
		}
		puts("");
	}

	return 0;
}
