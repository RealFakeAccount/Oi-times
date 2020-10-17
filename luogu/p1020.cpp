#include <set>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int a[MAXN];
multiset<int> S;

int main()
{
	int N = 1;
	while(scanf("%d", &a[i])) ++i;
	N--;
	for(int i = 1; i <= N; i++) S.insert(a[i]);
	 
	return 0;
}