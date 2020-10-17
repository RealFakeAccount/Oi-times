#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e2 + 10;

int N, a[MAXN];
char ans[MAXN];
int cnt[MAXN];

int main()
{
	cin>>N;
	for(int i = 1; i <= N; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= N; i++) cnt[a[i]]++;

	int sig = 0;
	for(int i = 1; i <= N; i++) if(cnt[a[i]] == 1)
		++sig, ans[i] = (sig & 1 ? 'A' : 'B');

	if(!(sig & 1)){
		puts("YES");
		for(int i = 1; i <= N; i++) {
			if(cnt[a[i]] == 1) printf("%c", ans[i]);
			else putchar('A');
		}
	}
	else {
		int pos = 0;
		for(int i = 1; i <= N; i++) if(cnt[a[i]] > 2) {
			pos = i; break;
		}
		if(pos == 0) return puts("NO"), 0;
		puts("YES");
		for(int i = 1; i <= N; i++) {
			if(cnt[a[i]] == 1) printf("%c", ans[i]);
			else if(i == pos) putchar('B');
			else putchar('A');
		}
	}
	return 0;
}
