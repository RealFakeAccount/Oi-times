#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 250 + 10;

int N, W;
int w[MAXN], t[MAXN];

double p[MAXN]; double f[1010];
inline bool check(double x)
{
	for(int i = 1; i <= N; i++) p[i] = 1.0 * t[i] - 1.0 * x * w[i];
	fill(f, f + W + 1, -(1 << 29));
	f[0] = 0;
	for(int i = 1; i <= N; i++){
		for(int j = W; j >= 0; j--)
			f[min(W, j + w[i])] = max(f[min(W, j + w[i])], f[j] + p[i]);
	}
 	return f[W] >= 0;
}

int main()
{
	cin>>N>>W;
	double l = 0, r = 0;
	for(int i = 1; i <= N; i++) 
		scanf("%d%d", &w[i], &t[i]), r += t[i];

	while(r - l > 1e-4){
		double mid = (l + r) / 2;
		if(check(mid)) l = mid;
		else r = mid;
	}
 	cout<<(int)(l * 1000)<<endl;
	return 0;
}
