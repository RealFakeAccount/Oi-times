#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int v[3], m[3];

int main()
{
	freopen("mixmilk.in", "r", stdin);
	freopen("mixmilk.out", "w", stdout);
	for(int i = 0; i < 3; i++)
		v[i] = read(), m[i] = read();
	int T = 0, p0 = 0, p1 = 1;
	while(T < 100) {
		if(m[p0] <= v[p1] - m[p1]) 
			m[p1] += m[p0], m[p0] = 0;
		else m[p0] -= v[p1] - m[p1], m[p1] = v[p1];
		++T, ++p0, ++p1;
		p0 %= 3, p1 %= 3;
	}
	for(int i = 0; i < 3; i++)
		printf("%d\n", m[i]);
	return 0;
}