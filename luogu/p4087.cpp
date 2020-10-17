#include <map>
#include <vector>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 1e6 + 20;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, G;

struct state
{
	int date, idx, delta, newidx;
	inline bool operator <(const state &rhs) const{
		return date < rhs.date;
	}
}pool[MAXN];

namespace stree
{
	#define mid ((l + r) >> 1)
	#define ls (o << 1)
	#define rs ((o << 1) | 1)

	int node[MAXN << 2];

	inline void pushup(int o){
		node[o] = max(node[ls], node[rs]);
	}

	int modify(int o, int l, int r, int p, int v){
		if(l == r) return node[o] += v, node[o];
		int tmp;
		if(p <= mid) tmp = modify(ls, l, mid, p, v);
		else tmp = modify(rs, mid + 1, r, p, v);
		return pushup(o), tmp;
	}
}

vector<int> cp;
void compress(){
	for(int i = 1; i <= N; i++) cp.push_back(pool[i].idx);
	cp.push_back((1 << 29));
	sort(cp.begin(), cp.end());
	cp.erase(unique(cp.begin(), cp.end()), cp.end());
	//for(int i = 0; i < cp.size(); i++) cout<<cp[i]<<" ";
	for(int i = 1; i <= N; i++){
		pool[i].newidx = upper_bound(cp.begin(), cp.end(), pool[i].idx) - cp.begin();
		//assert(pool[i].newidx >= 1);
	}
}

map<int, int> M;
int main()
{
	//freopen("p4087.in", "r", stdin);
	cin>>N>>G;

	int ans = 0;
	for(int i = 1; i <= N; i++){
		int date = read(), idx = read(), delta = read();
		pool[i] = (state){date, idx, delta};
	}
	sort(pool + 1, pool + N + 1);

	compress(); int maxlast = 0;
	M[0] = (1 << 29);
	
	for(int i = 1; i <= N; i++){
		maxlast = stree::node[1];
		int val = stree::modify(1, 1, cp.size(), pool[i].newidx, pool[i].delta);
		
		if(M.find(val) == M.end()) M[val] = 0;
		M[val - pool[i].delta]--, M[val]++;
		
		int maxnow = stree::node[1];
		if(val < maxnow && (val - pool[i].delta) == maxlast) ++ans;//
		if(val == maxnow){
			if((val - pool[i].delta) == maxlast && M[val] + M[maxlast] == 1) continue;
			++ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}