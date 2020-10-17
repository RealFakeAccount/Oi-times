// luogu-judger-enable-o2
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
const int MAXN = 2e3 + 10;
const int BASE = 131;

int L, Q;
char mp[MAXN][MAXN], tmp[MAXN][MAXN];
int f[MAXN][MAXN];
ull p[MAXN], lh[MAXN], rh[MAXN];

inline int calc1(int i, int j){
    int l = 1, r = min(j - 1, L - j);
    while(l < r){
        int mid = (l + r + 1) >> 1;
        if(lh[j] - lh[j - mid - 1] * p[mid + 1] ==
           rh[j] - rh[j + mid + 1] * p[mid + 1]) l = mid;
        else r = mid - 1;
    }
    return (l << 1) + 1;
}

void solve0(){
    for(int i = 1; i <= L; i++) {
        lh[0] = rh[L + 1] = 0;
        for(int j = 1; j <= L; j++) 
            lh[j] = lh[j - 1] * BASE + mp[i][j] - 'a';
        for(int j = L; j >= 1; j--)
            rh[j] = rh[j + 1] * BASE + mp[i][j] - 'a';
    
        for(int j = 1; j <= L; j++) {
            if(mp[i][j - 1] == mp[i][j + 1])
                f[i][j] = max(f[i][j], calc1(i, j));
            f[i][j] = max(f[i][j], 1);
        }
    }
}

void solve1(){
    for(int i = 1; i <= L; i++) {
        lh[0] = rh[L + 1] = 0;
        for(int j = 1; j <= L; j++) 
            lh[j] = lh[j - 1] * BASE + mp[i][j] - 'a';
        for(int j = L; j >= 1; j--)
            rh[j] = rh[j + 1] * BASE + mp[i][j] - 'a';
    
        for(int j = 1; j <= L; j++) {
            if(mp[i][j - 1] == mp[i][j + 1])
                f[j][i] = max(f[j][i], calc1(i, j));
            f[j][i] = max(f[j][i], 1);
        }
    }
}

int main()
{
    cin>>L>>Q;
    for(int i = 1; i <= L; i++){
        scanf(" ");
        for(int j = 1; j <= L; j++) 
            tmp[j][i] = mp[i][j] = getchar();
    }
    
    p[0] = 1;
    for(int i = 1; i <= L; i++) p[i] = p[i - 1] * BASE;
    solve0();
    memcpy(mp, tmp, sizeof(mp));
    solve1();
    if(L == 1) f[1][1] = 1;
    while(Q--){
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", f[x][y]);
    }
    return 0;
}