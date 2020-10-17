#include <cmath>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 3e2 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, a[MAXN];

int main()
{
	cin>>N;
	for(int i = 1; i <= N; i++) a[i] = read();
	sort(a + 1, a + N + 1); long long ans = 0;
	
	int l = 0, r = N + 1; bool d = 0;
	while(l < r) {
		if(!d) ans += pow(a[r - 1] - a[l], 2), --r;
		else ans += pow(a[l + 1] - a[r], 2), ++l;
		d ^= 1;
	}
	cout<<ans<<endl;
	return 0;
}