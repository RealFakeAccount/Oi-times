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
ll a[MAXN], b[MAXN];

int main()
{
	cin>>N;
	for(int i = 1; i <= N; i++) b[i] = read();
	int Q; cin>>Q;
	while(Q--){
		int x = read(), y = read();
		memcpy(a, b, sizeof(a));
		while(x--){
			int lst = a[1];
			for(int i = 1; i < N; i++) (a[i] += a[i + 1]) %= MOD;
			(a[N] += lst) %= MOD;
		}
		
		cout<<a[y] % MOD<<endl;
	}
	return 0;
}