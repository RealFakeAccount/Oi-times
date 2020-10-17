#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define fir first
#define sec second
typedef pair<int, int> P;
typedef long long ll;
const int MAXN = 200000 + 20;
const int mod = 10007;
inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

int N, w[MAXN];
vector<int> g[MAXN]; int fa[MAXN];
int dep[MAXN]; P ans(0, 0);

int main()
{
	cin>>N;
	for(int i = 1, u, v; i < N; i++)
 	{
 		u = read(), v = read();
 		g[u].push_back(v), g[v].push_back(u);
 	}
 	for(int i = 1; i <= N; i++) w[i] = read();
 	
 	for(int i = 1; i <= N; i++)
 	{
 		int mx = 0, sum = 0;
 		for(int j = 0; j < (int) g[i].size(); j++)
 		{
 			int u = g[i][j];
 			ans.fir = max(ans.fir, w[u] * mx);
 			mx = max(mx, w[u]);
 			ans.sec = ((ll) ans.sec + sum * w[u]) % mod;
 			sum = ((ll) sum + w[u]) % mod;
 		}
 	}

 	cout<<ans.fir<<" "<<((ll) ans.sec * 2 % mod)<<endl;
	return 0;
}