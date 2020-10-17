#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;

set<ll> ans;
bool vis[66000];
int comp[100], prime[10000];

int main(){
    ios::sync_with_stdio(false);
    freopen("11752.out", "w", stdout);
    for(int i = 2; i <= 65536; i++) if(!vis[i])
        for(int j = 2; j * i <= 65536; j++) vis[i * j] = true;

    int p1 = 0;
    for(int i = 2; i <= 65; i++) 
        if(vis[i]) comp[++p1] = i; 

    int p2 = 0;
    for(int i = 2; i <= 65536; i++) 
        if(!vis[i]) prime[++p2] = i;

    for(int i = 2; i <= 65536; i++) {
        int lim = ceil(64.0 * log(2) / log(i)) - 1;
        if(i == 2) lim = 63; 
        for(int j = 1; comp[j] <= lim; j++)
            ans.insert(pow(i, comp[j]));
    }

    ans.insert(1);
    for(auto i : ans) cout<<i<<endl;
    return 0;
}