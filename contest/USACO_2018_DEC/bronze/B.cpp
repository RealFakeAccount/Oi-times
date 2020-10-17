#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e2 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N;
int s[MAXN], t[MAXN], b[MAXN];
int val[MAXN * 10];

int main()
{
	freopen("blist.in", "r", stdin);
	freopen("blist.out", "w", stdout);
	cin>>N;
	for(int i = 1; i <= N; i++)
		s[i] = read(), t[i] = read(), b[i] = read();
	for(int i = 1; i <= N; i++) 
		val[s[i]] += b[i], val[t[i] + 1] -= b[i];

	int ans = 0, cur = 0;
	for(int i = 1; i <= 1000; i++) 
		cur += val[i], ans = max(ans, cur);
	printf("%d\n", ans);
	return 0;
}