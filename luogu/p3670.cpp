#include <set>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 5e2 + 10;
const int MAXM = 50 + 5;

int N, M;
char str[MAXN << 1][MAXM];

struct gene
{
	char a, b, c;
	gene(char a, char b, char c) : a(a), b(b), c(c) {}
	bool operator <(const gene &rhs) const{
		if(rhs.a != a) return a < rhs.a;
		if(b != rhs.b) return b < rhs.b;
		else return c < rhs.c;
	}
};

set<gene> S;

int main()
{
	//freopen("p3670.in", "r", stdin);
	cin>>N>>M;
	for(int i = 1; i <= (N << 1); i++) scanf(" %s", str[i] + 1);
	int ans = 0;
	for(int i = 1; i <= M; i++)
		for(int j = i + 1; j <= M; j++)
			for(int k = j + 1; k <= M; k++){
				S.clear();			
				for(int p = 1; p <= N; p++) 
					S.insert(gene(str[p][i], str[p][j], str[p][k]));
				bool flag = false;
				for(int p = N + 1; p <= (N << 1); p++) 
					if(S.find(gene(str[p][i], str[p][j], str[p][k])) != S.end()){
						flag = true; break;
					}
				ans += (!flag);
			}
	cout<<ans<<endl;
	return 0;
}
