#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100+10;
int n, d;
int vec[maxn];

int main() {
    cin >> n >> d;
    for (int i = 0; i < n; i++) cin >> vec[i];
    sort(vec, vec+n);
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (vec[j]-vec[i] > d) break;
            ans = max(ans, j-i+1);
        }
    }
    cout << n-ans << endl;
    
    return 0;
}
