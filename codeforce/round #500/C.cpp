#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN = 1e5 + 20;
typedef long long ll;
inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch -'0', ch = getchar();
	return x;
}

int a[MAXN << 1];
int N;

int main()
{
	cin>>N;
	if(N == 1){
		puts("0"); return 0;
	}
	for(int i = 1; i <= (N << 1); i++) a[i] = read();
	sort(a + 1, a + (N << 1) + 1);
	ll ans = (1LL << 62);
	for(int i = 2; i <= N; i++)
		ans = min(ans, (1LL * a[i + N - 1] - a[i]) * (1LL * a[N << 1] - a[1]));
	ans = min(ans, (1LL * a[N << 1] - a[N + 1]) * (1LL * a[N] - a[1]));
	cout<<ans<<endl; 
	return 0;
}