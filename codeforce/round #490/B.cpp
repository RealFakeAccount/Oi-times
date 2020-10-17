#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 1e2 + 20;

string s; int N;
int pri[MAXN], cnt = 0;

void calc()
{
	cnt = 0;
	for(int i = 1; i * i <= N; i++)
		if(N % i == 0)
		{
			pri[++cnt] = i;
			if(i != N / i) pri[++cnt] = N / i;
		}
	sort(pri + 1, pri + cnt + 1);
}

int main()
{
	cin>>N>>s;
	calc();
	for(int i = 1; i <= cnt; i++)
		reverse(s.begin(), s.begin() + pri[i] );
	cout<<s<<endl;
	return 0;
}
