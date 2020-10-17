#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e3 + 10;
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
	sort(a + 1, a + N + 1);
	int cnt = 0;
	for(int i = 2; i <= N; i++)
		cnt += a[i] - a[i - 1] - 1;
	cout<<cnt<<endl;
	return 0;
}