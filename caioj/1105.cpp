#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
using namespace std;
struct Line {
    int x, y1, y2;
    bool in;
} *_a_, *_b_;
Line a[10000], b[10000];
int f[88888];
bool g[88888]; 
int i, n = 0, x1, y1, x2, y2;
long ans = 0;
inline int cmp_line(const void *a, const void *b) {
    _a_ = (Line *)a, _b_ = (Line *)b;
    if (_a_->x > _b_->x) return 1;
    if (_a_->x < _b_->x) return -1;
    return _a_->in ? -1 : 1;
}
void insert(const long t, const int l, const int r) {
    if (l >= y1 && r <= y2 && !g[t]) {
        if (!f[t]++) ans += r - l;
        return ;
    }
    long mid = (l + r) / 2, t1 = t << 1, t2 = t1 | 1;
    f[t1] += f[t], f[t2] += f[t], f[t] = 0; 
    if (mid >= y2) insert(t1, l, mid);
    else if (mid <= y1) insert(t2, mid, r);
    else insert(t1, l, mid), insert(t2, mid, r);
    g[t] = f[t1] || f[t2] || g[t1] || g[t2];
}
void erase(const long t, const int l, const int r) {
    if (l >= y1 && r <= y2 && !g[t]) {
        if (!--f[t]) ans += r - l;
        return ;
    }
    long mid = (l + r) / 2, t1 = t << 1, t2 = t1 | 1;
    f[t1] += f[t], f[t2] += f[t], f[t] = 0;
    if (mid >= y2) erase(t1, l, mid);
    else if (mid <= y1) erase(t2, mid, r);
    else erase(t1, l, mid), erase(t2, mid, r);
    g[t] = f[t1] || f[t2] || g[t1] || g[t2];
}
int main() {
    for (scanf("%d", &i); i; --i) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        a[n].x = x1, a[n].y1 = y1, a[n].y2 = y2, a[n].in = true;
        b[n].x = y1, b[n].y1 = x1, b[n].y2 = x2, b[n++].in = true;
        a[n].x = x2, a[n].y1 = y1, a[n].y2 = y2, a[n].in = false;
        b[n].x = y2, b[n].y1 = x1, b[n].y2 = x2, b[n++].in = false;
    }
    qsort(a, n, sizeof(Line), cmp_line);
    memset(f, 0, sizeof f);
    memset(g, 0, sizeof g);
    for (i = 0; i < n; ++i) {
        y1 = a[i].y1, y2 = a[i].y2;
        a[i].in ? insert(1, -10000, 10000) : erase(1, -10000, 10000);
    }
    qsort(b, n, sizeof(Line), cmp_line);
    memset(f, 0, sizeof f);
    memset(g, 0, sizeof g);
    for (i = 0; i < n; ++i) {
        y1 = b[i].y1, y2 = b[i].y2;
        b[i].in ? insert(1, -10000, 10000) : erase(1, -10000, 10000);
    }
    cout<<ans;
    return 0;
}
