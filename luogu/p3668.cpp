#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 20;
inline int read()
{
    int x = 0; char ch = getchar();
    while(!isdigit(ch)) ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x;
}

int N;
int a[MAXN];bool vis[MAXN];

struct P
{
    int l, r;
    bool operator <(const P &rhs) const{
        l < rhs.l;
    }
};

map<int, P> col;
vector<P> seg;

inline bool cmp(const P &lhs, const P &rhs) {
    if(lhs.first == rhs.first) return lhs.second > rhs.second;
    return lhs.first < rhs.first;
}

int main()
{
    cin>>N;
    for(int i = 1; i <= N; i++){
        int cur = read();
        if(col.find(cur) == col.end()) col[cur].l = col[cur].r = i;
        else col[cur].r = i;
    }
    for(map<int, P>::iterator it = col.begin(); it != col.end(); ++it)
        seg.push_back(it->second);

    sort(seg.begin(), seg.end(), cmp);
    int l = 0, r = 0; bool flag = true;
    int cnt = 0, ans = 0;
    for(int i = 0; i < (int) seg.size(); i++){
        if(seg[i].first > r) 
            l = seg[i].first, r = seg[i].second, cnt = 0;
        if(seg[i].second > r) {
            flag = false; break;
        }

    }
    if(!flag) puts("-1");
    else cout<<ans<<endl;
    return 0;
}