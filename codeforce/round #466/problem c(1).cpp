#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<char> enabled;
vector<char>::iterator iter;
int n, k;
char minc;
string orig, ans;

bool update(int it) {
    if (it+1 < k) ans[it+1] = minc;
    iter = upper_bound(enabled.begin(), enabled.end(), ans[it]);
    if (iter != enabled.end()) {
        ans[it] = *iter;
        return true;
    }
    return false;
}

int main() {
    cin >> n >> k >> orig;
    minc = 'z';
    for (int i = 0; i < orig.length(); i++)
        { enabled.push_back(orig[i]); minc = min(minc, orig[i]); }
    sort(enabled.begin(), enabled.end());
    iter = unique(enabled.begin(), enabled.end());
    enabled.resize( distance(enabled.begin(), iter) );
    ans = orig; bool flag = ans.length() < k;
    while (ans.length() < k) ans.push_back(minc);
    while (ans.length() > k) ans.pop_back();
    int it = k-1;
    while (true && !flag) {
        if (update(it)) break;
        it--;
    }
    cout << ans << endl;
    return 0;
}
