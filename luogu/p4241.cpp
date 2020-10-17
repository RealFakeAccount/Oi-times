#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 19260817;
const int MAXM = 1e5 + 10;
const int MAXN = 5e2 + 10;
inline int read(){
    char ch = getchar(); int x = 0;
    while(!isdigit(ch)) ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x;
}

int N, M;
int f[MAXM], w[MAXN * 50];

int main(){
    cin>>N>>M;
    int n = 0, tmp = (1 << 30);
    for(int i = 1; i <= N; i++) {
        int k = read(), d = read();
        tmp = min(tmp, d);
        for(int j = 1; j <= k; j <<= 1) 
            w[++n] = j * d, k -= j;
        if(k) w[++n] = d * k;
    }

    f[0] = 1;
    for(int i = 1; i <= n; i++) 
        for(int j = M; j >= w[i]; j--)
            (f[j] += f[j - w[i]]) %= MOD;
        
    int ans = 0;
    for(int i = M - tmp + 1; i <= M; i++) (ans += f[i]) %= MOD;
    printf("%d\n", ans);
    return 0;
}