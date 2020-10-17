#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e6 + 20;
typedef long long ll;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N;
long long f[MAXN], A, B, C;
long long sum[MAXN], q[MAXN];

inline ll mypow(int x){
	return 1LL * x * x;
}

inline double calc(int j, int k){
	return (1.0 * f[j] - f[k] + A * (mypow(sum[j]) - mypow(sum[k])) - B * (sum[j] - sum[k]))
	/ (1.0 * 2 * A * (sum[j] - sum[k]));
}

int main()
{
	cin>>N;
	cin>>A>>B>>C;
	for(int i = 1; i <= N; i++) sum[i] = sum[i - 1] + read();
	int l = 0, r = 0;
	for(int i = 1; i <= N; i++){
		while(l < r && calc(q[l], q[l + 1]) <= sum[i] * 1.0) ++l;
		int j = q[l];
		f[i] = f[j] + A * mypow(sum[i] - sum[j]) + B * (sum[i] - sum[j]) + C;
		 while(l < r && calc(q[r - 1], q[r]) >= calc(q[r], i)) --r;
		 q[++r] = i;
	}
	cout<<f[N]<<endl;
	return 0;
}