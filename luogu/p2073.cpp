#include <set>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
inline int read(){
    char ch = getchar(); int x = 0; bool flag = false;
    while(!isdigit(ch)) flag |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return flag ? -x : x;
}

set<int> Hash;
set<P> S;

int main(){
    int opt, ans1 = 0, ans2 = 0; set<P>::iterator it;
    while(opt = read(), opt != -1) {
        if(opt == 1) {
            int w = read(), c = read();
            if(Hash.find(c) != Hash.end()) continue;
            Hash.insert(c), S.insert(P(c, w));
            ans1 += w, ans2 += c;
        }
        else if(opt == 2) {
            if(S.empty()) continue;
            it = S.end(); --it;
            Hash.erase(it->first);
            ans1 -= it->second, ans2 -= it->first;
            S.erase(it);
        }
        else if(opt == 3) {
            if(S.empty()) continue;
            it = S.begin();
            Hash.erase(it->first);
            ans1 -= it->second, ans2 -= it->first;
            S.erase(it);
        }
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}