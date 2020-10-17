#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int MAXN = 20 + 5;
const int MAXS = 5e2 + 10;

int dx[2] = {0, 1}, dy[2] = {-1, -1};
int f[MAXN << 1][MAXN << 1][MAXS];
int C[MAXN << 1][MAXN << 1];
int N, S;

inline int getx(int x){
    return (x <= N ? (N - x + 1) : (x - N + 1));
}

vector<char> ch; 
void dfs(int x, int y, int cur)
{
    if(y == ((N << 1) - 1)) return ;
    if(y <= getx(x + 1) && f[x + 1][y][cur - C[x][y]] > 0)
        ch.push_back('L'), dfs(x + 1, y, cur - C[x][y]);

    else 
        ch.push_back('R'), dfs(x + 1, y + 1, cur - C[x][y]);
    return ;
}

void write(int cnt, int pos)
{
    ch.clear();
    dfs(1, pos, S);
    cout<<cnt<<" ";
    for(int i = 0; i < (int) ch.size(); i++)
        cout<<ch[i];
    puts("\n");
}

int main()
{
    while(cin>>N>>S, (N + S))
    {
        memset(C, 0, sizeof(C));
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= (N - i + 1); j++)
                scanf("%d", &C[i][j]);
        for(int i = N + 1; i < (N << 1); i++)
            for(int j = 1; j <= (i - N + 1); j++)
                scanf("%d", &C[i][j]);

       /*for(int i = 1; i < (N << 1); i++){
            for(int j = 1; j <= getx(i); j++)
                cout<<C[i][j]<<" ";
            cout<<endl;
        }*/

        memset(f, 0, sizeof(f));
        for(int i = 1; i <= N; i++)
            f[ (N << 1) - 1 ][i][ C[(N << 1) - 1][i] ] = 1;

        for(int i = (N << 1) - 2; i >= 1; i--){
            for(int j = 1; j <= getx(i); j++){

                int m = i + 1, n = j;
                if(n <= getx(m)){
                    for(int k = C[i][j]; k <= S; k++)
                        f[i][j][k] += f[m][n][k - C[i][j]];
                }

                m = i + 1, n = j + 1;
                if(n <= getx(m)){
                    for(int k = C[i][j]; k <= S; k++)
                        f[i][j][k] += f[m][n][k - C[i][j]];
                }
            }
        }
        P ans(0, INF);
        for(int i = 1; i <= N; i++)
        if(f[1][i][S] > 0){
            ans.first += f[1][i][S];
            ans.second = min(ans.second, i);
        }
        if(!ans.first) puts("0\n");
        else write(ans.first, ans.second);
    }

    return 0;
}
