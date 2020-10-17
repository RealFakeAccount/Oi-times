#include <iostream>
#include <algorithm>
using namespace std;

const long long INF = 1000000000;
long long tom[55], ban[55];
long long ans[55];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < n; i++) cin >> tom[i];
    for (int i = 0; i < m; i++) cin >> ban[i];
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        long long prod = -INF*INF-1;
        for (int j = 0; j < n && j < n; j++) {
            for (int k = 0; k < m; k++) {
                prod = max(prod, tom[i]*ban[j]);
            }
        }
        ans[cnt++] = prod;
    }
    sort(ans, ans+cnt);
    cout << ans[cnt-2] << endl;
    
    return 0;
}
