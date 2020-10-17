#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e2 + 10;
inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch -'0', ch = getchar();
	return x;
}

bool a[MAXN];

int main()
{
	int N, M;
	cin>>N>>M;
	for(int i = 1; i <= N; i++) {
		int l = read(), r = read();
		for(int j = l; j <= r; j++) a[j] |= 1;
	}
	int cnt = 0;
	for(int i = 1; i <= M; i++) if(!a[i]) ++cnt;
	printf("%d\n", cnt);
	for(int i = 1; i <= M; i++) if(!a[i]) printf("%d ", i);
	return 0;
}