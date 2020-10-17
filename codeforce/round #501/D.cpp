#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

inline void putll(unsigned n) {
	if (n == 0) return puts("0"), void();
	static int ch[40];
	int cnt = 0;
	while (n) ch[cnt++] = n % 10, n /= 10;
	while (cnt--) putchar(ch[cnt] + '0');
	putchar(' ');
}

void calc(ll now, ll k) {
	ll one = now;
	ll two = now == 1 ? 2 : now - 1;
	bool f = false;
	for(; k; k--) {
		if(f)
			putll(one), f = false;
		else
			putll(two), f = true;
	}
}

int main() 
{
	ll n, k, s;
	cin>>n>>k>>s;
	ll a = n - 1;
	if(a * k < s || s < k) {
		puts("NO");
		return 0;
	}
	puts("YES");
	bool f = false;
	while(s - a >= k - 1) {
		if(f)
			putll(1), f = false;
		else
			putll(n), f = true;
		k --;
		s -= a;
	}
	
	if(k > 0) {
		if(f)
			putll(n - (s - k + 1)), calc(n - (s - k), --k);
		else
			putll(1 + (s - k + 1)), calc(1 + (s - k), --k);
	}
	return 0;
}