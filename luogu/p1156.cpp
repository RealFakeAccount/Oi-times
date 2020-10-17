#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 1e2 + 5;

int D, G;
struct rub
{
    int ti, fe, hei;
    bool operator <(const rub &lhs) const {
        return ti < lhs.ti;
    }
}r[MAXN];

int f[105][205];

int main()
{
    //freopen("p1156.in", "r", stdin);
    cin>>D>>G;
    for(int i = 1, t, fe, h; i <= G; i++){
        scanf("%d%d%d", &t, &fe, &h);
        r[i] = (rub) {t, fe, h};
    }
    sort(r + 1, r + G + 1);
    memset(f, -0x3f, sizeof(f));

    r[0] = (rub) {0, 0, 0}; r[G + 1] = r[G];
    f[0][0] = 10;

    for(int i = 0; i <= G; i++){
        bool flag = false; int gap = r[i + 1].ti - r[i].ti;

        for(int j = 0; j <= D; j++) if(f[i][j] >= 0){
            
            if(f[i][j] + r[i].fe >= gap){
                flag = true;
                f[i + 1][j] = max(f[i + 1][j], f[i][j] - gap + r[i].fe);
            }

            if(j + r[i].hei >= D) {
                cout<<r[i].ti<<endl;
                return 0;
            }

            if(f[i][j] >= gap) f[i + 1][j + r[i].hei] = max(f[i + 1][j + r[i].hei], f[i][j] - gap);
        }
        if(!flag) break;
    }

    int ans = 10;
    for(int i = 1; i <= G; i++){
        if(ans < r[i].ti) break;
        ans += r[i].fe;
    } 
    cout<<ans<<endl;
    return 0;
}
