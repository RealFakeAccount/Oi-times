#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 20 + 1;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, B;

vector<P> aw[MAXN];//first->points, second->awards; 

int tabel[MAXN][MAXN];
int f[(1 << MAXN)], bitcnt[(1 << MAXN)];

int bitcount(int x){
	return x ? (x & 1) + bitcount(x >> 1) : 0;
}

int main()
{
	cin>>N>>B;
	for(int i = 0; i < B; i++){
		int k = read(), p = read(), a = read();
		aw[k].push_back(P(p, a));
	}
	for(int i = 1; i <= N; i++)
		for(int j = 0; j < N; j++) tabel[i][j] = read();
	for(int i = 0; i < (1 << N); i++) bitcnt[i] = bitcount(i);

	for(int i = 0; i < (1 << N); i++){
		for(int j = 0; j < N; j++) if(!(i & (1 << j))){
			int tmp = i | (1 << j);
			f[tmp] = max(f[tmp], f[i] + tabel[bitcnt[tmp]][j]);

			for(int k = 0; k < (int) aw[bitcnt[tmp]].size(); k++)
				if(f[i] + tabel[bitcnt[tmp]][j] >= aw[bitcnt[tmp]][k].first)
					f[tmp] = max(f[tmp], f[i] + tabel[bitcnt[tmp]][j] + aw[bitcnt[tmp]][k].second);
			cout<<i<<" "<<f[i]<<endl;
		}
	}
	cout<<f[(1 << N) - 1]<<endl;
	return 0;
}