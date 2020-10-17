#include <set>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 5e2 + 10;

int N, M;
char mp[MAXN][MAXN];

inline bool out(int x, int y){
	return !(1 <= x && x <= N && 1 <= y && y <= M);
}

struct state
{
	int x, y, stp;
	bool g;//true->up, false->down

	inline int fall(){return x + (g ? -1 : 1);}

	vector<state> expand(){
		vector<state> cur;
		if(out(fall(), y)) return cur;

		if(mp[fall()][y] != '#') {
			cur.push_back((state){fall(), y, stp, g}); 
			return cur;
		}

		int nx = x, ny = y + 1;
		while(!out(nx, ny) && mp[fall()][ny] == '#' && mp[nx][ny + 1] != '#')
			cur.push_back((state){nx, ny, stp, g}), ++ny;
		if(!out(nx, ny)) cur.push_back((state){nx, ny, stp, g});
		nx = x, ny = y - 1;
		while(!out(nx, ny) && mp[fall()][ny] == '#' && mp[nx][ny - 1] != '#')
			cur.push_back((state){nx, ny, stp, g}), --ny;
		if(!out(nx, ny)) cur.push_back((state){nx, ny, stp, g});

		cur.push_back((state){x, y, stp + 1, g ^ 1});
		return cur;
	}

	int Hash(){
		return ((x * 500 + y) << 1) | g;
	}
};

set<int> S;
queue<state> q;

int bfs(){
	state st;
	int sx, sy, tx, ty;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++){
			if(mp[i][j] == 'C') sx = i, sy = j;
			else if(mp[i][j] == 'D') tx = i, ty = j;
		}
	st = (state){sx, sy, 0, false};
	S.insert(st.Hash()); q.push(st);
	while(!q.empty()){
		state u = q.front(); q.pop();

		vector<state> nxt = u.expand();
		for(vector<state>::iterator it = nxt.begin(); it != nxt.end(); ++it){
			if(it->x == tx && it->y == ty) return it->stp;
			if(S.find(it->Hash()) != S.end()) continue;

			S.insert(it->Hash());
			q.push(*it);
		}
	}
	return -1;
}
//5 5
//#####
//#...#
//#...D
//#C...
//##.##
int main()
{
	cin>>N>>M;
	for(int i = 1; i <= N; i++){
		scanf(" ");
		for(int j = 1; j <= M; j++)
			mp[i][j] = getchar();
	}
	cout<<bfs()<<endl;
	return 0;
}
