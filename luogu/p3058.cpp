#include <stack>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e3 + 10;
const int MOD = 2012;

int N;
string s;
bool isok[MAXN][MAXN];
int f[MAXN];

int main()
{
	freopen("p3058.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin>>s; N = s.size();
	f[0] = 2;
	for(int i = 0; i < N; i++){
		stack<char> sta; sta.push(s[i]);
		if(i) f[i] += f[i - 1];
		for(int j = i + 1; j < N; j++){
			if(s[j] == '(') sta.push('(');
			else if(!sta.empty() && sta.top() == '(') sta.pop();
			else sta.push(')');
			if(sta.empty()) f[j] += 2;
		}
	}
	// for(int i = 0; i < N; i++) cout<<f[i]<<" ";
	cout<<f[N - 1]<<endl;
	return 0;
}