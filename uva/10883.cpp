#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN = 5e5 + 20;

double logc[MAXN], a[MAXN];
int N;

int main()
{
	int T, t = 0; cin>>T;
	while(T--)
	{
		cin>>N;
		for(int i = 0; i < N; i++) scanf("%lf", &a[i]);
		logc[0] = log10(1);
		for(int i = 0; i < N; i++)
			logc[i + 1] = logc[i] + log10(N - 1 - i) - log10(i + 1);
		double ans = 0;
		for(int i = 0; i < N; i++)
			if(a[i] < 0) ans -= pow(10, logc[i] + log10(-a[i]) - log10(2) * (N - 1));
			else ans += pow(10, logc[i] + log10(a[i]) - log10(2) * (N - 1));
		printf("Case #%d: %.3lf\n", ++t, ans);
	}
	return 0;
}