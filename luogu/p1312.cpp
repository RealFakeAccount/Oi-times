// luogu-judger-enable-o2
#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
int N;
int mp[9][7];

inline bool done(){
    for(int i = 1; i <= 7; i++)
        for(int j = 1; j <= 5; j++) if(mp[i][j]) return false;
    return true;
}

inline void calc(){
    bool era[9][7];
    memset(era, false, sizeof(era));
    bool flag = true;

    while(flag){
        flag = false; memset(era, false, sizeof(era));
        for(int i = 1; i <= 7; i++){
            for(int j = 1; j <= 5; j++) if(mp[i][j]){
                if(mp[i - 1][j] == mp[i][j] && mp[i][j] == mp[i + 1][j]) flag = true;
                if(mp[i][j - 1] == mp[i][j] && mp[i][j] == mp[i][j + 1]) flag = true;
                if(i != 1 && mp[i - 1][j] == 0) flag = true;
                if(flag) break;
            }if(flag) break;
        }if(!flag) break;

        for(int i = 1; i <= 7; i++){
            for(int j = 1; j <= 5; j++) if(mp[i][j]){
                if(mp[i - 1][j] == mp[i][j] && mp[i][j] == mp[i + 1][j])
                    era[i - 1][j] = era[i][j] = era[i + 1][j] = true;
                if(mp[i][j - 1] == mp[i][j] && mp[i][j] == mp[i][j + 1])
                    era[i][j - 1] = era[i][j] = era[i][j + 1] = true;
            }
        }

        for(int i = 1; i <= 7; i++)
            for(int j = 1; j <= 5; j++)
                if(era[i][j]) mp[i][j] = 0;

        for(int i = 2; i <= 7; i++)
            for(int j = 1; j <= 5; j++)
                if(mp[i][j] && mp[i - 1][j] == 0)
                    swap(mp[i][j], mp[i - 1][j]);
    }
}

vector<pair<P, int> > step;
bool dfs(int cnt){
    if(cnt == N) return done();

    // cout<<cnt<<endl;

    int tmp[9][7];
    memcpy(tmp, mp, sizeof(tmp));

    for(int j = 1; j <= 5; j++){
        for(int i = 1; i <= 7; i++) if(tmp[i][j]){
            if(j != 5){
                memcpy(mp, tmp, sizeof(tmp));
                swap(mp[i][j + 1], mp[i][j]); calc();
                if(dfs(cnt + 1)){
                    return step.push_back(make_pair(P(j - 1, i - 1), 1)), true;
                }
            }
            
            if(j != 1){
                memcpy(mp, tmp, sizeof(tmp));
                swap(mp[i][j - 1], mp[i][j]); calc();
                if(dfs(cnt + 1)) {
                    return step.push_back(make_pair(P(j - 1, i - 1), -1)), true;
                }
            }
        }
    }
    return false;
}

int main()
{
	freopen("p1312.in", "r", stdin);
    cin>>N;
    for(int i = 1; i <= 5; i++){
        int tmp, p = 0;
        while(scanf(" %d", &tmp), tmp != 0) mp[++p][i] = tmp;
    }
    if(!dfs(0)) puts("-1");
    else {
        reverse(step.begin(), step.end());
        for(int i = 0; i < (int) step.size(); i++)
            printf("%d %d %d\n", step[i].first.first, step[i].first.second, step[i].second);
    }
    return 0;
}