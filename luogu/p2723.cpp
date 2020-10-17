#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXK = 1e2 + 10;
const int MAXN = 1e5 + 20;

int N, K;
int a[MAXK], f[MAXN], s[MAXK];

int main()
{
	cin>>K>>N;
	for(int i = 1; i <= K; i++) scanf("%d", &a[i]);
	f[0] = 1;
	for(int i = 1; i <= N; i++){
		int tmp = 0x7f7f7f7f;
		for(int j = 1; j <= K; j++){
			while(a[j] * f[s[j]] <= f[i - 1]) ++s[j];
			tmp = min(tmp, a[j] * f[s[j]]);
		}
		f[i] = tmp;
	}
	printf("%d\n", f[N]);
	return 0;
}