#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e4 + 10;
const int MAXM = 1e3 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, M, K;
int up[MAXN], down[MAXN];

struct Pipe
{
	int pos, L, H;
}pipe[MAXN];

int f[2][MAXM];

int main()
{
	cin>>N>>M>>K;
	for(int i = 1; i <= N; i++)
		up[i] = read(), down[i] = read();
	for(int i = 1; i <= K; i++) 
		pipe[i].pos = read(), pipe[i].L = read(), pipe[i].H = read();

	int p = 1;
	for(int i = 1; i <= N; i++) {
		memset(f[i & 1], 0x3f, sizeof(f[i & 1]));
		
		if(pipe[p].pos == i){
			for(int j = pipe[p].L; j <= pipe[p].H; ++j){
				if(j > up[i - 1]) 
					f[i & 1][j] = min(f[i & 1][j], f[(i - 1) & 1][j - up[i - 1]] + 1);

			}
		}
		else {

		}
	}
	return 0;
}