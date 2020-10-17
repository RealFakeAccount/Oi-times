#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 20;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

inline int read()
{
    int x = 0; char ch = getchar();
    while(!isdigit(ch)) ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x;
}

int N, M;
int a[MAXN], f[MAXN][MAXN];

namespace BIT
{
    int c[MAXN];
    inline int lowbit(int x)
    {
        return x & (-x);
    }

    inline void add(int x, int v)
    {
        while(x <= N)
            c[x] = (c[x] + v) % mod,
            x += lowbit(x);
    }

    inline int ask(int x)
    {
        int ans = 0;
        while(x > 0)
            ans = (ans + c[x]) % mod,
            x -= lowbit(x);
        return ans;
    }

}

vector<int> cp;
inline void compress()
{
    for(int i = 0; i <= N; i++)
        cp.push_back(a[i]);

    sort(cp.begin(), cp.end());
    cp.erase(unique(cp.begin(), cp.end()), cp.end());

    for(int i = 0; i <= N; i++)
        a[i] = upper_bound(cp.begin(), cp.end(), a[i]) - cp.begin();
}

int main()
{
    freopen("12983.in", "r", stdin);
    freopen("12983.out", "w", stdout);
    int T;
    cin>>T;

    int cnt = 0;
    while(cnt < T)
    {
        N = read(), M = read();
        for(int i = 1; i <= N; i++)
            a[i] = read();
        
        memset(f, 0, sizeof(f));
        a[0] = -INF, f[0][0] = 1;
        compress();

        using namespace BIT;
        {
            for(int i = 1; i <= M; i++)
            {
                memset(c, 0, sizeof(c));
                add(a[0], f[i - 1][0]);
                for(int j = 1; j <= N; j++)
                {
                    f[i][j] = ask(a[j] - 1);
                    add(a[j], f[i - 1][j]);
                }
            }
        }
        
        int ans = 0;
        for(int i = 1; i <= N; i++)
            ans = (ans + f[M][i]) % mod;
        cout<<"Case #"<<++cnt<<": "<<ans<<endl;
    }
    return 0;
}
