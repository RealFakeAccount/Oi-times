#include <cmath>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int T;

int bitcount(int x) {
	return x ? bitcount(x >> 1) + (x & 1) : 0;
}

inline ll calc(int x) {
	ll tmp = 1;
	while(x) tmp <<= 1, --x;
	return tmp;
}

int main()
{
	cin>>T;
	while(T--) cout<<calc(bitcount(read()))<<endl;
	return 0;
}