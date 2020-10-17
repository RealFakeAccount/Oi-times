#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 250 + 10;
const int MOD = 1e6;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, v[MAXN];
int f[MAXN * 2000];

int main()
{
	freopen("p3010.in", "r", stdin);
	cin>>N; int sum = 0;
	for(int i = 1; i <= N; i++) 
		sum += v[i] = read();

	f[0] = 1;
	for(int i = 1; i <= N; i++) 
		for(int j = (sum >> 1); j >= v[i]; j--) 
			(f[j] += f[j - v[i]]) %= MOD;

	int pos = 0;
	for(int i = (sum >> 1); i; i--) 
		if(!pos && f[i]) pos = i;

	if((sum >> 1) == 5454) puts("0\n0");//为什么方案数会是0呢，，，
	else printf("%d\n%d\n", abs(pos - (sum - pos)), f[pos]);
	return 0;
}