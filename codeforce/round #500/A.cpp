#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 50  + 2;
inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch -'0', ch = getchar();
	return x;
}

int a, b;
int N;

int main()
{
	cin>>N; a = 0, b = 0;
	for(int i = 1; i <= N; i++) a += read();
	for(int i = 1; i <= N; i++) b += read();
	if(a >= b) puts("Yes");
	else puts("No");
	return 0;
}