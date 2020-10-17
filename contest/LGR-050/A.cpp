#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e6 + 10;
const int MOD = 998244353;
typedef long long ll;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N;
int a[MAXN + 2020]; ll sum[MAXN + 2020];

int main()
{
	cin>>N;
	for(int i = 1; i <= N; i++) a[i] = read();
	for(int i = N + 1; i <= N + 2010; i++) a[i] = a[i - N];
	for(int i = 1; i <= N + 2010; i++) sum[i] = (sum[i - 1] + a[i]) % MOD;
	int Q; cin>>Q;
	while(Q--){
		int x = read(), y = read();
		ll s = (sum[y + x - 1] - sum[y]) * x % MOD;
		cout<<(s + a[y] + a[x + y]) % MOD<<endl;
	}
	return 0;
}
