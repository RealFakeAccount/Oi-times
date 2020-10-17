#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 200 + 10;

struct People
{
    int a, b;
    bool operator >(const People &rhs) const{
        return b > rhs.b;
    }
}pe[MAXN];

int N;
int f[2][MAXN * MAXN];
int sum[MAXN];

int main()
{   
    cin>>N;
    for(int i = 1; i <= N; i++)
        scanf("%d%d", &pe[i].a, &pe[i].b);
    sort(pe + 1, pe + N + 1, greater<People>());
    for(int i = 1; i <= N; i++) sum[i] = sum[i - 1] + pe[i].a;
    memset(f, 0x3f, sizeof(f)); 

    int tmp = 0, d = 0; f[d][0] = 0;
    for(int i = 1; i <= N; i++){
        d ^= 1; memset(f[d], 0x3f, sizeof(f[d]));
        for(int j = 0; j <= tmp; j++){
            f[d][j + pe[i].a] = min(f[d][j + pe[i].a], max(f[d ^ 1][j], j + pe[i].a + pe[i].b));
            f[d][j] = min(f[d][j], max(f[d ^ 1][j], sum[i] - j + pe[i].b));
        }
        tmp += pe[i].a;
    }
    
    int ans = (1 << 29);
    for(int i = 0; i <= tmp; i++) ans = min(ans, f[d][i]);
    cout<<ans;
    return 0;
}