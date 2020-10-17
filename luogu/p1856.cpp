#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 5000 + 20;

inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N;
struct P
{
	int x, y;
	P(int x = 0, int y = 0) : x(x), y(y) {}
}co[MAXN];

namespace stree
{
	#define mid (((l) + (r)) >> 1)
	#define ls ((o) << 1)
	#define rs (((o) << 1) | 1)

	struct _node
	{

	}node[MAXN << ]
}

int main()
{
	cin>>N;
	for(int i = 1; i <= N; i++)
		co[i].x = read() + 1e4 + 1, 
		co[i].y = read() + 1e4 + 1;


	return 0;
}