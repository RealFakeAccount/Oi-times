#include <cmath>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 5e5 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N;
bool vis[MAXN];int col[MAXN];

int main()
{
	cin>>N; int ans = 0;
	for(int i = 1; i <= N; i++) {
		col[i] = read();
		if(col[i] != col[1]) vis[i] = true;
	}
	for(int i = 2; i <= N; i++) {
		if(vis[i]) ++ans;
		for(int j = i; j <= N; j += i)
			if(col[i] != col[j]) vis[j] = true;
	}
	printf("%d\n", ans + 1);
	return 0;
}