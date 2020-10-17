#include <queue>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
const int MAXN = 5e4 + 10;
inline int read()
{
    int x = 0; char ch = getchar();
    while(!isdigit(ch)) ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x;
}

int N, G, B, D;
int res[MAXN];
P a[MAXN];
priority_queue<P> q;

int main()
{
    cin>>N>>G>>B>>D;
    for(int i = 1; i <= N; i++)
        a[i].first = read(), a[i].second = read(),
        q.push(P(a[i].second, i));
    a[++N] = P(D, 0); q.push(P(0, N));
    sort(a + 1, a + N + 1);
    for(int i = 1; i < N; i++) if(a[i + 1].first - a[i].first > G) 
        return puts("-1"), 0;
    ll ans = 0; int cnt = 0;
    while(!q.empty()){
        P p = q.top(); q.pop();
        
    }
    return 0;
}