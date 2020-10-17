#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 2e5 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int a[MAXN], g[MAXN];
int N; int sta[MAXN];

int main()
{
	cin>>N;
	for(int i = 1; i <= N; i++) a[i] = read();

	int ans = 1, p = 0;
	sta[++p] = a[1];
	for(int i = 2; i <= N; i++){
		while(p > 0 && a[i] > (sta[p] << 1)) --p;
		sta[++p] = a[i];
		ans = max(ans, p);
	}
	cout<<ans<<endl;
	return 0;
}