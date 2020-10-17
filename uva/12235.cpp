#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e2 + 5;
const int MAXH = (1 << 8) + 2;

int f[2][MAXN][MAXH][10];//前i个, 选j个, 书架上剩余书目集合, 最后一本书的高度
int N, K;

int main()
{
    int T = 0;
    while(cin>>N>>K, (N + K))
    {
        int d = 0, all = 0;
        memset(f[d], 0x3f, sizeof(f[d]));
        for(int i = 0; i < N; i++){
            int h; scanf("%d", &h);
            h -= 25;
            d ^= 1; memset(f[d], 0x3f, sizeof(f[d]));
            f[d][i][(1 << h)][h] = 1;
            for(int j = 0; j <= min(i, K); j++)
                for(int s = all; s; s = (s - 1) & all)
                    for(int k = 0; k < 8; k++){
                        if(f[d ^ 1][j][s][k] == INF) continue;
                        if(h == k) f[d][j][s][h] = min(f[d][j][s][h], f[d ^ 1][j][s][k]);//不拿
                        else {
                            f[d][j][s | (1 << h)][h] = min(f[d][j][s | (1 << h)][h], f[d ^ 1][j][s][k] + 1);
                            f[d][j + 1][s][k] = min(f[d][j + 1][s][k], f[d ^ 1][j][s][k]);//拿
                        }
                    }
            all |= (1 << h);
        }
        int ans = INF;
        for(int j = 0; j <= K; j++)
            for(int s = all; s; s = (s - 1) & all)
                for(int k = 0; k < 8; k++){
                    if(f[d][j][s][k] == INF) continue;
                    int cnt = 0;
                    for(int tmp = s ^ all; tmp; tmp >>= 1)
                        if(tmp & 1) ++cnt;
                    ans = min(ans, f[d][j][s][k] + cnt);
                }
        printf("Case %d: %d\n\n", ++T, ans);
    }
    return 0;
}