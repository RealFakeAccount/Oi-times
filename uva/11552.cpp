#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 1000 + 20;
const int INF = 0x3f3f3f3f;

int f[MAXN][27];
int bsize, K;
bool vis[27];
string str;

int main()
{
	//freopen("11552.in", "r", stdin);
	//freopen("11552.out", "w", stdout);
	int T;cin>>T;
	while(T--)
	{
		cin>>bsize>>str;
		K = (int) str.size() / bsize;
		
		memset(f, 0x3f, sizeof(f));
		memset(vis, false, sizeof(vis));
		int cnt = 0;
		for(int i = 0; i < bsize; i++)
			if(!vis[str[i] - 'a']){
				vis[str[i] - 'a'] = true;
				++cnt;
			}
		for(int i = 'a' - 'a'; i <= 'z' - 'a'; i++)
			if(vis[i]) f[0][i] = cnt;

		for(int i = 0; i < K - 1; i++)
		{
			memset(vis, false, sizeof(vis));
			cnt = 0;
			for(int j = (i + 1) * bsize; j < (i + 2) * bsize; j++)
				if(!vis[str[j] - 'a']) {
					vis[str[j] - 'a'] = true;
					++cnt;
				}
				
			for(int p = 'a' - 'a'; p <= 'z' - 'a'; p++)
				if(f[i][p] != INF)
			for(int j = 'a' - 'a'; j <= 'z' - 'a'; j++)
				if(vis[j]){
					if(j != p){
						if(cnt != 1 && vis[p])
							f[i + 1][j] = min(f[i + 1][j], f[i][p] + cnt - 1);
						else f[i + 1][j] = min(f[i + 1][j], f[i][p] + cnt); 
					}
					else {
						if(cnt == 1 && vis[p])
							f[i + 1][j] = min(f[i + 1][j], f[i][p] + cnt - 1);
						else f[i + 1][j] = min(f[i + 1][j], f[i][p] + cnt);
					}
				}
		}
		int ans = INF;
		for(int i = 'a' - 'a'; i <= 'z' - 'a'; i++)
			ans = min(ans, f[K - 1][i]);
		cout<<ans<<endl;
	}
	return 0;
}
