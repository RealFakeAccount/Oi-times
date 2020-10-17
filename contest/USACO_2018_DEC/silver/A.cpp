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

int N, M, C;
int a[MAXN];

inline bool check(int x) {
	int cnt = 1, lst = a[1], tot = 1;
	for(int i = 2; i <= N; i++) {
		if(a[i] - lst > x || tot >= C) 
			++cnt, lst = a[i], tot = 1;
		else ++tot;
	}
	return cnt <= M;

}

int main() {
	freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);
	cin>>N>>M>>C;
	for(int i = 1; i <= N; i++) a[i] = read();
	sort(a + 1, a + N + 1);
	int l = 0, r = 1e9;//!!!
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
	return 0;
}
