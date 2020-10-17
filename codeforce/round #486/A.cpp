#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 100 + 20;

bool a[MAXN];
std::vector<int> v;

int main()
{
	int N, K;
	cin>>N>>K;
	int cnt = 0;
	for(int i = 1, c; i <= N; i++)
	{
		cin>>c;
		if(!a[c])
		{
			cnt++; a[c] = true;
			v.push_back(i);
		}
	}	
	if(cnt >= K)
	{
		puts("YES");
		for(int i = 0; i < K; i++)
			cout<<v[i]<<" ";
	}
	else puts("NO");

	return 0;
}