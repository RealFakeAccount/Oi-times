#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 250 + 5;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int N;
int B[MAXN][MAXN];
bool vis[MAXN][MAXN];

inline int getnum(int x, int y){
	return x * N + y;
}

inline bool out(int x, int y){
	return !(1 <= x && x <= N && 1 <= y && y <= N);
}

namespace ufs
{
	int fa[MAXN], siz[MAXN];

	void init(){for(int i = 1; i <= (N * N); i++) fa[i] = i, siz[i] = 1;}
	int findfa(int x){return fa[x] == x ? x : findfa(fa[x]);}
	inline void unite(int x, int y){fa[x = findfa(x)] = (y = findfa(y)), siz[y] += siz[x];}
}

int ans1 = 0;
void dfs1(int x, int y){
	vis[x][y] = true;
	for(int i = 0; i < 4; i++){
		int vx = x + dx[i], vy = y + dy[i];
		if(out(vx, vy)) continue;
		if(!vis[vx][vy] && B[x][y] == B[vx][vy]){
			ufs::unite(getnum(x, y), getnum(vx, vy));
			ans1 = max(ans1, ufs::siz[getnum(vx, vy)]);
			dfs1(vx, vy);
		}
	}
}

vector<int> dfs2(int x, int y, int c){
	using namespace ufs;
	vis[x][y] = true;
	vector<int> tmp, res;
	for(int i = 0; i < 4; i++){
		int vx = x + dx[i], vy = y + dy[i];
		if(out(vx, vy)) continue;

		if(findfa(getnum(vx, vy)) != findfa(getnum(x, y)))
				res.push_back(findfa(getnum(vx, vy)));
		else if(!vis[x][y]){
			tmp = dfs2(vx, vy, c);
			for(int i = 0; i < (int) tmp.size(); i++) res.push_back(tmp[i]);
		}  
	}
	return res;
}

int ans2 = 0;
void calc(int x, int y){
	using namespace ufs;
	vector<int> res = dfs2(x, y, B[x][y]);
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());

	map<int, int> M;
	for(int i = 0; i < res.size(); i++){
		int cur = findfa(res[i]);
		int col = B[cur / N][cur % N];
		if(M.find(col) == M.end()) M[col] = siz[cur];
		else M[col] += siz[cur];
		ans2 = max(ans2, M[col]);
	}
}

int main()
{
	cin>>N; ufs::init();
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++) B[i][j] = read();

	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++) if(!vis[i][j]) dfs1(i, j);

	cout<<ans1<<endl;
	memset(vis, false, sizeof(vis));

	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++) if(!vis[i][j]) calc(i, j);

	cout<<ans2<<endl;
	return 0;
}