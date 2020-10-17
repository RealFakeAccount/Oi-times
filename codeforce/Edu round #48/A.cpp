#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 2e5 + 20;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, M;
int a[MAXN];

int main()
{
	cin>>N>>M;
	for(int i = 1; i <= N; i++) a[i] = read();
	int cnt = 0;
	for(int i = 1; i <= N; i++){
		int ans = 0;
		if(cnt + a[i] < M) {
			puts("0"); cnt += a[i]; continue;
		} 
		else{
			++ans;
			a[i] -= (M - cnt);
			cnt = a[i] % M;
			ans += a[i] / M;
		}
		printf("%d ", ans);
	}
	return 0;
}