#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
const int MAXN = 25 + 2;

map<string, int> Map;
map<int, int> num;
int N, M;

bool d[MAXN][MAXN];
vector<string> v[MAXN];
string name[MAXN];

namespace ufs
{
	int fa[MAXN];
	void init(){for(int i = 1; i <= N; i++) fa[i] = i;}
	int findfa(int x){return fa[x] == x ? x : findfa(fa[x]);}
	inline void unite(int x, int y){fa[findfa(y)] = findfa(x);}
}

inline void init()
{
	for(int i = 1; i <= N; i++)
		v[i].clear();
	memset(d, false, sizeof(d));
	num.clear();
	Map.clear();
}

int main()
{
	int T = 0;
	while(cin>>N>>M, N != 0)
	{
		T++;
		ufs::init();
		init();
		int cnt = 0;
		string s1, s2;
		int n1, n2;
		for(int i = 1; i <= M; i++)
		{
			cin>>s1>>s2;
			if(Map.find(s1) == Map.end()) Map[s1] = ++cnt, name[cnt] = s1;
			if(Map.find(s2) == Map.end()) Map[s2] = ++cnt, name[cnt] = s2;
			n1 = Map[s1], n2 = Map[s2];
			d[n1][n2] |= 1;
		}

		for(int i = 1; i <= N; i++)
			d[i][i] |= 1;

		for(int k = 1; k <= N; k++)
			for(int i = 1; i <= N; i++)
				for(int j = 1; j <= N; j++)
					d[i][j] |= d[i][k] & d[k][j];

		using namespace ufs;
		for(int i = 1; i <= N; i++)
			for(int j = i + 1; j <= N; j++)
				if(d[i][j] & d[j][i])
					unite(i, j);

		cnt = 0;
		for(int i = 1; i <= N; i++)
			if(num.find(findfa(i)) == num.end())
				num[fa[i]] = ++cnt;
		for(int i = 1; i <= N; i++)
			v[num[fa[i]]].push_back(name[i]);

		printf("Calling circles for data set %d:\n", T);
		for(int i = 1; i <= N; i++)
		{
			if(v[i].empty()) break;
			for(int j = 0; j < (int) v[i].size(); j++)
			{
				if(j != 0) printf(", ");
				cout<<v[i][j];
			}	
			puts("");
		}	
	}
	return 0;
}