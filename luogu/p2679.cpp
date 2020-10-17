#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e3 + 10;
const int MAXM = 2e2 + 10;

int N, M, K;
char a[MAXN], b[MAXM];

int f[MAXN][MAXM][MAXM];

int dp(int posa, int posb, int k){
	if(k > K || posa >= a.size() || posb >= b.size()) return 0;
	if(f[posa][posb][k] != -1) return f[posa][posb][k];
	if(posb == b.size() - 1 && k == K) return f[posa][posb][k] = 1;

	int tmp = 0;
	if(posa < a.size() - 1 && a[posa + 1] == b[posb + 1])
		(tmp += dp(posa + 1, posb + 1, k)) %= MOD;

	for(int i = posa + 1; i < a.size(); i++)
		if(a[i] == b[posb + 1]) (tmp += dp(i, posb + 1, k + 1)) %= MOD;
	return f[posa][posb][k] = tmp;
}

int main()
{
	// freopen("p2679.in", "r", stdin);
	cin>>N>>M>>K;
	scanf("%s %s", a + 1, b + 1);

	for(int i = 1; i <= N; i++)
		

	return 0;
}