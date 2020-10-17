#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 5e4 + 20;
typedef long long ll;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, L;

ll f[MAXN], g[MAXN];
int q[MAXN];

inline double calc(int j, int k){
	return (double) (f[k] - f[j] + pow(g[k] + L + 1, 2) - pow(g[j] + L + 1, 2)) /
		(2.0 * (g[k] - g[j]));
}

int main()
{
	cin>>N>>L;
	for(int i = 1; i <= N; i++) g[i] = g[i - 1] + read();
	for(int i = 1; i <= N; i++) g[i] += i;
	int l = 0, r = 0;
	for(int i = 1; i <= N; i++) {
		while(l < r && 1.0 * g[i] >= calc(q[l], q[l + 1])) ++l;
		f[i] = f[q[l]] + pow(g[i] - g[q[l]] - L - 1, 2);
		while(l < r && calc(q[r], i) < calc(q[r - 1], q[r])) --r;
		q[++r] = i;
	}
	cout<<f[N]<<endl;
	return 0;
}