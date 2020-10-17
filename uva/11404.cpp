#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, string> P;
const int MAXN = 1e3 + 20;

string str;
string a, b;
P ans;
int f[MAXN >> 1][MAXN >> 1];

void init()
{
	a = str;
	b = reverse(str.begin(), str.end());
	int N = str.size();
	memset(f, 0, sizeof(f));
	for(int i = 0; i < N; i++)
		for(int j = 0; j <= i; j++)
		{
			if(a[i] == b[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
			else f[i][j] = max(f[i][j], max(f[i - 1][j], f[i][j - 1]));
		}
}

inline void calc(int p)
{

}

int main()
{
	ios::sync_with_stdio(false);
	while(cin>>str)
	{
		init();
		ans.first = 0;
		for(int p = 0; p < (int) str.size(); p++) 
			calc(p);

	}
	return 0;
}