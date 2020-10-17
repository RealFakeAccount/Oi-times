#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <windows.h>
#define pi 3.1415925
#define INF 0x3f3f3f3f
#define esp 1e-6
typedef long long ll;
using namespace std;
class point{
protected :
	int x, y;
public :
	point (int x1 = 0, int y1 = 0)
	{
		x = x1;
		y = y1;
	}
};

class circle : public point {
protected :
	int r;
public :
	circle (int x1 = 0, int y1 = 0, int rr = 0)	: point (x1, y1)
	{
		r = rr;
	}
	void area() {
		cout << "圆心，半径为： " << x << "," << y << "," << r <<endl;
		cout << "圆面积为： " << pi * r * r << endl;
	}
};

ll ksm(ll a,ll b,ll c) {
	ll r = 1;
	a = a % c;
	while (b) {
		if(b & 1)	r = (r * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}
	return r;
}
const int N = 1e5 + 7;
int ans[N];
int main(void)
{
 	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, cnt = 0;
	string s1, s2;
	cin >> n >> s1 >> s2;
	for (int i = 0; i < n; i++) {
		if (s1[i] == s2[i])
			continue;
		else {
			for (int j = i + 1; j < n; j++)
				if (s2[i] == s1[j]) {
					for (int k = j - 1; k >= i; k--) {
						swap(s1[k + 1], s1[k]);
						ans[++cnt] = k + 1;
					//	cout << "*******" <<endl;
					}
					break;
				}
				else if (j == n - 1) {
					cout << -1;
					return 0;
				}
		}
	}
	if (cnt > 10000 || cnt == 0) {
		if (s1 == s2 )
			cout << 0;
		else
			cout << -1;
		return 0;
	}
		
	cout << cnt << endl;
	for (int i = 1; i <= cnt; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
