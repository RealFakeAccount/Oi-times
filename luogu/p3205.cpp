#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1e3 + 20;
const int mod = 19650827;

int N, f[MAXN][MAXN][2], t[MAXN];

int main()
{
	cin>>N;
	for(int i = 1; i <= N; i++)
		scanf(" %d" ,&t[i]);

	for(int i = 1; i <= N; i++)
		f[i][i][0] = 1;

	int r;
	for(int len = 2; len <= N; len++)
		for(int l = 1; (l + len - 1) <= N; l++)
		{
			r = l + len - 1;
			f[l][r][0] = f[l + 1][r][0] * (t[l] < t[l + 1]) +
						 f[l + 1][r][1] * (t[l] < t[r]);
			f[l][r][1] = f[l][r - 1][0] * (t[r] > t[l]) + 
						 f[l][r - 1][1] * (t[r] > t[r - 1]);  
			f[l][r][0] %= mod,
			f[l][r][1] %= mod;
		}

	cout<<(f[1][N][0] + f[1][N][1]) % mod<<endl;



	return 0;
}
