#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 20;
inline int read()
{
    int x = 0; char ch = getchar();
    while(!isdigit(ch)) ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x;
}

int N; ll M;
ll s[MAXN], f[MAXN];

namespace stree
{
    #define mid ((l + r) >> 1)
    #define ls (o << 1)
    #define rs ((o << 1) | 1)

    ll node[MAXN << 2];

    inline void pushup(int o){
        node[o] = max(node[ls], node[rs]);
    }

    void build(int o, int l, int r){
        if(l == r) return node[o] = s[l], void();
        build(ls, l, mid), build(rs, mid + 1, r);
        return pushup(o);
    }

    ll query(int o, int l, int r, int a, int b){
        if(l > b || r < a) return -1;
        if(a <= l && r <= b) return node[o];
        return max(query(ls, l, mid, a, b), query(rs, mid + 1, r, a, b)); 
    }
}

int main()
{
	//freopen("p4085.in", "r", stdin);
    cin>>N>>M;
    for(int i = 1; i <= N; i++)
        f[i] = read(), s[i] = read();

    stree::build(1, 1, N);
    int l = 1, r = 1; ll sum = 0;
    ll ans = (1LL << 50);
    while(true){
    	while(sum < M && r <= N) sum += f[r++]; 
    	if(sum < M) break;
    	ans = min(ans, stree::query(1, 1, N, l, r));
    	sum -= f[l++];
    }
    cout<<ans<<endl;
    return 0;
}