#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e2 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N;

int main()
{
	cin>>N;
	bool flag = false;
	for(int i = 1; i <= N; i++) flag |= read() == 1;
	if(flag) puts("HARD");
	else puts("EASY");
	return 0;
}