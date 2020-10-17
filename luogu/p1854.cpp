// luogu-judger-enable-o2
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAXF = 1e2 + 20;

inline int read()
{
    static int x;
    scanf("%d", &x);
    return x;
}

int f[MAXF][MAXF], pre[MAXF][MAXF];
int B[MAXF][MAXF];
int F, V;

int main()
{
    cin>>F>>V;
    for(int i = 1; i <= F; i++)
        for(int j = 1; j <= V; j++)
            B[i][j] = read();

    memset(f, -0x7f, sizeof(f));
    for(int i = 1; i <= (V - F + 1); i++)
        f[1][i]=B[1][i], pre[1][i] = i;

    for(int i = 2; i <= F; i++)
        for(int j = i; j <= V - F + i; j++)
            for(int k = 1; k < j; k++)
                if(f[i - 1][k] + B[i][j] > f[i][j])
                {
                    f[i][j] = f[i - 1][k] + B[i][j];
                    pre[i][j] = k;
                }

    int ans = -0x7f7f7f7f,y;
    for(int i = 1; i <= V; i++)
        if(ans < f[F][i])
             y = i, ans = f[F][i];

    int x = F;
    std::vector<int> v;
    for(; x >= 1; y = pre[x][y], x--)
        v.push_back(y);

    reverse(v.begin(), v.end());
    cout<<ans<<endl;
    for(int i = 0; i < (int) v.size(); i++)
        cout<<v[i]<<" ";
    puts("");
    return 0;
}
