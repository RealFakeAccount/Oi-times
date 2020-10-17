//  Created by Sengxian on 2016/11/23.
//  Copyright (c) 2016Äê Sengxian. All rights reserved.
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 18, INF = 0x3f3f3f3f;
int n, m, dp[1 << MAX_N], ss[MAX_N][MAX_N];
double x[MAX_N], y[MAX_N];

inline void cal(int i, int j, double &a, double &b) {
    a = (y[i] - y[j] * (x[i] / x[j])) / (x[i] * x[i] - x[i] * x[j]);
    b = (y[i] - a * x[i] * x[i]) / x[i];
}

inline int dcmp(const double &a, const double &b) {
    return fabs(a - b) < 1e-8 ? 0 : (a < b ? -1 : 1);
}

void process() {
    double a, b;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            cal(i, j, a, b);
            if (dcmp(a, 0) != -1) {
                ss[i][j] = (1 << n) - 1;
                continue; // a not equal 0
            }
            ss[i][j] = 0;
            for (int k = 0; k < n; ++k)
                if (dcmp(a * x[k] * x[k] + b * x[k], y[k]) != 0)
                    ss[i][j] |= (1 << k);
        }
}

inline void tension(int &a, const int &b) {
    if (b < a) a = b;
}

void solve() {
    dp[0] = 0;
    for (register int s = 1, i, j; s < (1 << n); ++s) {
        dp[s] = INF;
        i = __builtin_ctz(s);
        tension(dp[s], dp[s ^ (1 << i)] + 1);
        for (j = i + 1; j < n; ++j) if ((s >> j) & 1)
            tension(dp[s], dp[s & ss[i][j]] + 1);
    }
    printf("%d\n", dp[(1 << n) - 1]);
}

int main() {
    int caseNum;
    scanf("%d", &caseNum);
    for (int t = 0; t < caseNum; ++t) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) scanf("%lf%lf", x + i, y + i);
        process();
        solve();
    }
    return 0;
}
