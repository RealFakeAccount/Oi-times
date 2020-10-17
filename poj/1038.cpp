#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 150 + 5;
const int MAXM = 10  + 2;

int N, M, K;
bool badp[MAXN][MAXM];
int p[12] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049};
int f[2][60000];

inline int threetoten(int a[]){
	int tmp = 0;
	for(int i = 0; i < M; i++)
		tmp += a[i] * p[i];
	return tmp;
}

inline void tentothree(int x, int a[]){
	for(int i = 0; i < M; i++)
		a[i] = x % 3, x /= 3;
}

int pre[13], cur[13];
void dfs(int d, int j, int last, int state)
{
	int k;
	f[d][state] = max(f[d][state], last);
	if(j >= M) return ;
	if((j + 1) < M && (pre[j] == 0) && (pre[j + 1] == 0) && (cur[j] == 0) && (cur[j + 1] == 0)){
		cur[j] = cur[j + 1] = 2;
		k = threetoten(cur);
		dfs(d, j + 2, last + 1, k);
		cur[j] = cur[j + 1] = 0;
	}
	if((j + 2) < M && (cur[j] == 0) && (cur[j + 1] == 0) && (cur[j + 2] == 0)){
		cur[j] = cur[j + 1] = cur[j + 2] = 2;
		k = threetoten(cur);
		dfs(d, j + 3, last + 1, k);
		cur[j] = cur[j + 1] = cur[j + 2] = 0;
	}
	dfs(d, j + 1, last, state);
	return ;
}

int solve()
{
	int d = 0; int tmp;
	memset(f[d], -1, sizeof(f[d]));
	for(int i = 0; i < M; i++) pre[i] = (badp[1][i] ? 2 : 1);
	tmp = threetoten(pre);
	f[d][tmp] = 0;

	for(int i = 2; i <= N; i++){
		d ^= 1;
		memset(f[d], -1, sizeof(f[d]));

		for(int j = 0; j < p[M]; j++){
			if(f[d ^ 1][j] == -1) continue;
			tentothree(j, pre);
			for(int k = 0; k < M; k++){
				if(badp[i][k]) cur[k] = 2;
				else cur[k] = (pre[k] == 0 ? 0 : pre[k] - 1);
			}

			tmp = threetoten(cur);
			dfs(d, 0, f[d ^ 1][j], tmp);
		}
	}
	int ans = 0;
	for(int i = 0; i < p[M]; i++) ans = max(ans, f[d][i]);
	return ans;
}

int main()
{
	int T; cin>>T;
	while(T--)
	{
		cin>>N>>M>>K;
		memset(badp, false, sizeof(badp));
		for(int i = 1, x, y; i <= K; i++){
			scanf("%d%d", &x, &y);
			badp[x][y - 1] = true;
		}
		printf("%d\n", solve());
	}
	return 0;
}