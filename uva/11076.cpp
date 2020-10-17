#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
const int MAXN = 12 + 2;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N;
int a[10];
ull C[MAXN][MAXN];

int main()
{
	freopen("11076.in", "r", stdin);
	C[0][0] = 1;
	for(int i = 1; i <= 12; i++){
		C[i][0] = 1;
		for(int j = 1; j <= i; j++) 
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}
	while(scanf(" %d", &N) == 1, N){
		memset(a, 0x00, sizeof(a));
		for(int i = 1; i <= N; i++) a[read()]++;
		ull tmp = 1, cnt = N;
		for(int i = 0; i <= 9; i++) 
			tmp *= C[cnt][a[i]], cnt -= a[i];
		cout<<tmp<<endl;
		tmp /= N, cnt = 0;
		while(N--) (cnt *= 10) += 1;
		ull ans = 0;
		for(ull i = 0; i <= 9; i++) 
			ans += i * tmp * cnt * a[i];
		cout<<ans<<endl;
	}
	return 0;
}