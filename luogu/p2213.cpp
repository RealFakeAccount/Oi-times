#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 4e2 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, K;
int a[MAXN][MAXN], sum[MAXN][MAXN];

inline bool out(int x, int y){
	return !(1 <= x && x <= N && 1 <= y && y <= N);
}

int main()
{
	// freopen("p2213.in", "r", stdin);
	cin>>N>>K;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			a[i][j] = read();
	for(int i = 1; i <= N; i++)
		 for(int j = 1; j <= N; j++)
		 	sum[i][j] = sum[i - 1][j] + a[i][j];

	int ans = 0;
	for(int i = 1; i <= N; i++){
		int res = 0;
		for(int j = 0; j <= min(K, N - 1); j++)
			res += sum[min(i + K - j, N)][1 + j] - sum[max(i - K + j, 1) - 1][1 + j];
		ans = max(ans, res);
		// cout<<res<<" ";
		for(int j = 2; j <= N; j++){
			for(int k = K; k >= 0; k--){
				int x = i + k, y = j + K - k;
				if(!out(x, y)) res += a[x][y];
				x = i - k;
				if(!out(x, y)) res += a[x][y];
			}
			if(!out(i, j + K)) res -= a[i][j + K];
			for(int k = K; k >= 0; k--){
				int x = i - k, y = j - 1 - K + k;
				if(!out(x, y)) res -= a[x][y];
				x = i + k;
				if(!out(x, y)) res -= a[x][y];
			}
			if(!out(i, j - K - 1)) res += a[i][j - K - 1];
			// cout<<res<<" ";
			ans = max(ans, res);
		}
		// cout<<endl;
	}
	cout<<ans<<endl;
	return 0;
}