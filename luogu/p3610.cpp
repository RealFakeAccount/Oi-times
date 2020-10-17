#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
#define X first
#define Y second
const int L = 0;
const int U = 1;
const int R = 2;
const int D = 3;
const int MAXN = 20 + 2;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int N;
bool mp[MAXN][MAXN];

struct state
{
    P p1, p2;
    int t1, t2;

    bool operator <(const state &rhs) const{
        if(t1 != rhs.t1) return t1 < rhs.t1;
        if(t2 != rhs.t2) return t2 < rhs.t2;
        if(p1 != rhs.p1) return p1 < rhs.p1;
        return p2 < rhs.p2;
    }
};

map<state, int> M;
queue<state> q;

inline bool out(P p1){
    if(!(1 <= p1.X && p1.X <= N && 1 <= p1.Y && p1.Y <= N))
        return true;
    if(!mp[p1.X][p1.Y]) return true;
    return false;
}

int bfs(){
    state s;
    s.p1 = s.p2 = P(1, 1);
    s.t1 = U, s.t2 = R;

    q.push(s); M[s] = 0;
    while(!q.empty()){
        state cur = q.front(); q.pop();
        state nxt = cur;
        if(nxt.p1 == P(N, N) && nxt.p2 == P(N, N)) return M[cur];
        //cout<<M[cur]<<endl;

        //forward
        nxt.p1.X += dx[nxt.t1];
        nxt.p1.Y += dy[nxt.t1];
        if(out(nxt.p1)) nxt.p1 = cur.p1;
        nxt.p2.X += dx[nxt.t2];
        nxt.p2.Y += dy[nxt.t2];
        if(out(nxt.p2)) nxt.p2 = cur.p2;
        if(nxt.p1 == P(N, N) && nxt.p2 == P(N, N)) return M[cur] + 1;
        if(M.find(nxt) == M.end()){
            q.push(nxt); M[nxt] = M[cur] + 1;
        }
        //assert(!(nxt.p1.X == N && nxt.p1.Y == N && nxt.p2.X == N && nxt.p2.Y == N));

        //left
        nxt = cur;
        nxt.t1--;
        nxt.t2--;
        if(M.find(nxt) == M.end()){
            q.push(nxt); M[nxt] = M[cur] + 1;
        }

        //right
        nxt = cur;
        nxt.t1++;
        nxt.t2++;
        if(M.find(nxt) == M.end()){
            q.push(nxt); M[nxt] = M[cur] + 1;
        }
    }
    return -1;
}

int main()
{
    cin>>N;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++){
            char ch ;
            scanf(" %c", &ch);
            mp[i][j] = (ch == 'E');
        }
    cout<<bfs()<<endl;
    return 0;
}