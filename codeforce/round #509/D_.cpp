#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, H;
ll suma[MAXN], sumb[MAXN];

int main()
{
	cin>>N>>H; 
	int l = 0, r = 0;int p = 0;
	for(int i = 1; i <= N; i++){
		l = read(), r = read();
		suma[i] = suma[i - 1] + (r - l);
		sumb[i] = sumb[i - 1] + l - p, p = r; 
	}
	l = 0, r = 1;int  ans = H;
	while(r <= N){
		while(sumb[r] - sumb[l] < H && r <= N)
			ans = max(1LL * ans, suma[r] - max(suma[l - 1], 1LL * 0) + H), ++r;
		++l;
	}
	cout<<ans<<endl;
	return 0;
}