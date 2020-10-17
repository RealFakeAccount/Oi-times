#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 3e5 + 20;
typedef long long ll;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N;
int a[MAXN], b[MAXN];
ll suma[MAXN], sumb[MAXN];

int main()
{
	cin>>N;
	for(int i = 1; i <= N; i++) a[i] = read();
	for(int i = 1; i <= N; i++) b[i] = read();
	for(int i = 1; i <= N; i++) 
		suma[i] = suma[i - 1] + a[i],
		sumb[i] = sumb[i - 1] + b[i];
	 
	ll tot[2] = {0};
	for(int i = 1; i <= N; i++){
		tot[0] += 1LL * b[i] * (i);
		tot[1] += 1LL * a[i] * (i - 1);
	}
	for(int i = N; i >= 1; i--){
		tot[0] += 1LL * a[i] * (2 * N - i + 1);
		tot[1] += 1LL * b[i] * (2 * N - i);
	}
	ll lst = 0, ans = tot[0];
	// cout<<tot[1]<<" "<<tot[0]<<endl;
	for(int i = 1; i <= N; i++){
		if(i & 1){
			ans = max(ans, tot[0] + lst);
			lst += a[i] * (1LL * (i - 1) * 2);
			lst += b[i] * (1LL * (i - 1) * 2 + 1);
			tot[0] -= lst;
			ans = max(ans, tot[0] + lst);
		}
		else {
			ans = max(ans, tot[1] + lst);
			lst += b[i] * (1LL * (i - 1) * 2);
			lst += a[i] * (1LL * (i - 1) * 2 + 1);
			tot[1] -= lst;
			ans = max(ans, tot[1] + lst);
		}
		cout<<i<<": "<<lst<<" "<<tot[1]<<" "<<tot[0]<<endl;
	}
	cout<<ans<<endl;
	return 0;
}