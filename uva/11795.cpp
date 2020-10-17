#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 16 + 2;

int N;
int wea[MAXN], s;
long long f[(1 << MAXN)];
string str;

inline int lowbit(int x) {return x & (-x);}

long long dp(int state)
{
	if(f[state] != -1) return f[state];
	f[state] = 0;
	int weapon = s;
	for(int i = 0; i < N; i++)
		if(!(state & (1 << i))) weapon |= wea[i];

	for(int i = state; i; i -= lowbit(i)){
		int cur = lowbit(i);
		if(weapon & cur) f[state] += dp(state ^ cur);
	}
	return f[state];
}

int main()
{
	ios::sync_with_stdio(false);
	int T, t = 0; cin>>T;
	while(T--)
	{
		cin>>N;
		cin>>str; s = 0;
		for(int i = 0; i < (int) str.size(); i++) 
			s |= ((str[i] == '1') << i);
		
		memset(wea, 0, sizeof(wea));
		for(int i = 0; i < N; i++)
		{
			cin>>str;
			for(int j = 0; j < (int) str.size(); j++)
				wea[i] |= ((str[j] == '1') << j);
		}
		memset(f, -1, sizeof(f));
		f[0] = 1LL;
		cout<<"Case "<<++t<<": "<<dp((1 << N) - 1)<<endl;
	}
	return 0;
}
