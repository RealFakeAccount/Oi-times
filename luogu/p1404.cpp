#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 100000 + 20;
const int INF = 0x3f3f3f3f;
int N, M;
double a[MAXN];

inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

inline bool check(double mid)
{
	double ans = -INF, minval = INF;
	double s[MAXN], b[MAXN];

	for(int i = 1; i <= N; i++)
		b[i] = a[i] - mid;
	for(int i = 1; i <= N; i++)
		s[i] = s[i - 1] + b[i];

	for(int i = M; i <= N; i++)
	{
		minval = min(minval, s[i - M]);
		ans = max(ans, s[i] - minval);
	}

	if(ans >= 0) return true;
	else return false;

}

int main()
{
	freopen("p1404.txt", "r", stdin);
	cin>>N>>M;
	for(int i = 1; i <= N; i++)
		a[i] = read();

	double l = -INF, r = INF, eps = 1e-5;
	while(r - l > eps)
	{
		double mid = (l + r) / 2;
		if(check(mid)) l = mid;
		else r = mid;
	}

	cout<<(int) (r * 1000)<<endl;
	return 0;
}
