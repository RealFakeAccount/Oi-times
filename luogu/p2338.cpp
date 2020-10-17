#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e4 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N;
vector<int> D, T;

int main()
{
	cin>>N;
	for(int i = 1; i <= N; i++){
		char ch; int x;
		scanf(" %c %d", &ch, &x);
		if(ch == 'T') T.push_back(x);
		else D.push_back(x);
	}
	sort(T.begin(), T.end());
	sort(D.begin(), D.end());
	
	
	return 0;
}