#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
const int MAXN = 4e5 + 20;

int N, K;
list<char> s;
char ch[MAXN];
bool vis[MAXN];

int main()
{
	cin>>N>>K; bool flag = false;
	scanf("%s", ch + 1);

	for(int j = 'a'; j <= 'z'; j++)
		if(!flag)
		for(int i = 1; i <= N; i++)
		{
			if(ch[i] == (char) j)
				vis[i] = true, K--;
			if(K == 0) {flag = true; break;}
		}
	for(int i = 1; i <= N; i++)
		if(!vis[i])
			putchar(ch[i]);
	return 0;
}