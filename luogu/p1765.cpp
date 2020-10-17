#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
int tabel[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};

char str[210];

inline bool check(char ch) {
	return (('a' <= ch && ch <= 'z') || (ch == ' '));
}

int main()
{
	freopen("p1765.in", "r", stdin);
	int ans = 0; char ch;
	while(ch = getchar(), check(ch)) {
		if(ch == ' ') ++ans;
		else ans += tabel[ch - 'a'];
	}
	printf("%d\n", ans);
	return 0;
}
