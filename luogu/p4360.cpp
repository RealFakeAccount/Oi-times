#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 2e4 + 20;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N;
int d[MAXN], w[MAXN];
int g[MAXN], sumd[MAXN], sumw[MAXN];
int q[MAXN];

inline double calc(int k, int j){
	return (double) (sumd[k] * sumw[k] - sumd[j] * sumw[j]) / (sumw[k] - sumw[j]);
}

int main()
{
	//freopen("p4360.in", "r", stdin);
	cin>>N;
	for(int i = 1; i <= N; i++) w[i] = read(), d[i] = read();
	for(int i = N; i >= 1; i--) sumd[i] = sumd[i + 1] + d[i];
	int tot = 0;
	for(int i = 1; i <= N; i++){
		sumw[i] = sumw[i - 1] + w[i];
		tot += w[i] * sumd[i];
	}
	int l = 0, r = 0, ans = (1 << 29);
	for(int i = 1; i <= N; i++){
		while(l < r && calc(q[l], q[l + 1]) > 1.0 * sumd[i]) ++l;
		ans = min(ans, tot - (sumd[q[l]] * sumw[q[l]]) - sumd[i] * (sumw[i] - sumw[q[l]]));
		while(l < r && calc(q[r - 1], q[r]) <= calc(q[r], i)) --r;
		q[++r] = i;
	}
	cout<<ans<<endl;
	return 0;
}
