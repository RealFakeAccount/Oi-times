#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 5e3 + 10;

int N, S;
int f[MAXN], sumt[MAXN], sumc[MAXN];
int q[MAXN];

int main()
{
	cin>>N>>S; memset(f, 0x3f, sizeof(f));
	for(int i = 1, t, c; i <= N; i++){
		scanf("%d%d", &t, &c);
		sumt[i] = sumt[i - 1] + t;
		sumc[i] = sumc[i - 1] + c;
	}
	
	int l = 1, r = 1; q[1] = 0;
	f[0] = 0;
	for(int i = 1; i <= N; i++){
		while(l < r && f[q[l + 1]] - f[q[l]] <= (S + sumt[i]) * (sumc[q[l + 1]] - sumc[q[l]])) ++l;
		f[i] = f[q[l]] - (S + sumt[i]) * sumc[q[l]] + sumt[i] * sumc[i] + S * sumc[N];
		while(l < r && (f[q[r]] - f[q[r - 1]]) * (sumc[i] - sumc[q[r]]) >= (f[i] - f[q[r]]) * (sumc[q[r]] - sumc[q[r - 1]])) --r;
		q[++r] = i;
	}
	printf("%d\n", f[N]);
	return 0;
}