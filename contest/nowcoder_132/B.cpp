#include <climits>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	LL n, m, s, q;
	cin >> n >> m >> s >> q;
	LL l = INT_MAX, r = INT_MIN;
	for(int i = 0; i < s; i++) {
		LL a, b;
		cin >> a >> b;
		a--, b--;
		if(b / m - a / m > 1) {
			cout << "Impossible!" << endl;
			return 0;
		} 
		a = a % m, b = b % m;
		if(b <= a) b += m;
		l = min(l, a), r = max(r, b);
	}
	if(r - l > m - 1) {
		cout << "Impossible!" << endl;
		return 0;
	} 
	if(r - l < m - 1) {
		cout << "Uncertain!" << endl;
		return 0;
	}
	LL offset = l == 0 ? 0 : m - l, ans = 0;
	for(int i = 0; i < q; i++) {
		LL t;
		cin >> t;
		t --;
		LL x = (t + offset) / m + 1, y = (t + offset) % m + 1;
		// cout << x << ' ' << y << endl;
		ans ^= x ^ y;
	}
	cout << ans << endl;
	return 0;
}