#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 2e2 + 10;
typedef unsigned long long ll;
typedef long long ll;
inline int read()
{
    int x = 0; char ch = getchar(); bool flag = false;
    while(!isdigit(ch)) flag |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return flag ? -x : x;
}

int N;
P a[MAXN];
ll dis[MAXN];

inline int dist(P &p1, P &p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

map<vector<int>, int> M;
int main()
{
    freopen("p3134.in", "r", stdin);
    cin>>N;
    for(int i = 1; i <= N; i++) 
        a[i].first = read(), a[i].second = read();

    memset(dis, 0x3f, sizeof(dis));
    ll tmp = 0;
    for(int i = 1; i <= N; i++){
        dis[i] = min(dis[i], tmp);
        tmp += dist(a[i], a[i + 1]);
    }

    tmp = dist(a[N], a[1]);
    for(int i = N; i >= 1; i--){
        dis[i] = min(dis[i], tmp);
        tmp += dist(a[i], a[i - 1]);
    }

    vector<int> Path; 
    for(int i = 2; i < N; i++){
        int dir = (a[i].first * a[i + 1].second - a[i + 1].first * a[i].second) < 0;
        Path.push_bacK(dist(a[i], a[i + 1])), Path.push_bacK(dir);
    }    
    for(int i = 0; i < Path.size(); i += 2){
        for(int j = i + 2; j < Path.size(); j += 2){
            vector<int> tmp(Path.begin() + i, Path.begin() + j);
            if(M.find(tmp) == M.end()) M[tmp] = 1;
            else M[tmp]++;
        }
    }
    for(int i = 2; i <= N; i++){
        
    }
    return 0;
}