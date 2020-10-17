#include <iostream>
#include <cstring>
#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;

using namespace std;
int m, n, a[10100], ans = 0;
deque <int> b;
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++){
        bool flag = 0;
        for (int j = 0; j < b.size(); j++)
            if (a[i] == b[j]) {
                flag = 1;
                break;
            }
        if (!flag) {
            b.push_back(a[i]);
            if (b.size() > m) b.pop_front();
            ans++;
        }    
    }
    cout << ans << endl;
    return 0;
}