#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

int N;

void dfs(int x){
	putchar('2');
	if(x == 1) return;
	putchar('(');
	if(x == 0) {printf("0)"); return;}

	int tmp[16], p = 0;
	for(int i = 0; (1 << i) <= x; i++) if(x & (1 << i))
		tmp[++p] = i;
	
	while(p){
		dfs(tmp[p--]);
		if(p) putchar('+');
	}
	putchar(')');
}

int main()
{
	cin>>N;
	int tmp[16], p = 0;
	for(int i = 0; (1 << i) <= N; i++) if(N & (1 << i))
		tmp[++p] = i;
	while(p){
		dfs(tmp[p--]);
		if(p) putchar('+');
	}
	return 0;
}