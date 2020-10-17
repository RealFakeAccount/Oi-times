#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int MAXN = 10 + 2;

int M, N, a[MAXN];
int phi[10020];

void phi_()
{
	for(int i = 1; i <= 10010; i++) phi[i] = i;
	for(int i = 2; i <= 10010; i++)
		if(phi[i] == i)
			for(int j = i; j <= 10010; j += i)
				phi[j] = phi[j] / i * (i - 1);
}

inline int pow_(int d, int c, int m)
{
	int ans = 1;
	for(int i = 1; i <= c; i++)
		ans = (1ll * ans * d) % m;
	return ans;
}

int calc(int d, int m)
{
	if(d == N) return a[d] % m;

	int c = calc(d + 1, phi[m]) + phi[m];
	return pow_(a[d], c, m);
}

int main()
{
	//freopen("10692.out", "w", stdout);
	int T = 0;phi_();
	while(scanf("%d", &M) == 1)
	{
		T++;
		cin>>N;
		for(int i = 1; i <= N; i++) scanf("%d", &a[i]);
		printf("Case #%d: %d\n", T, calc(1, M));
	}
	return 0;
}