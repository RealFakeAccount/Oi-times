#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 1e2 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, D, M;
P a[MAXN];

int main()
{
	cin>>N>>D>>M;
	while(M--){
		int x = read(), y = read();
		int l = max(-x + D, x - D), r = min(x + D, -x + 2 * N - D);
		if(l <= y && y <= r) puts("YES");
		else puts("NO");
	}
	return 0;
}