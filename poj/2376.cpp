#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 25000 + 20;

int N, T;

struct inv
{
	int a, b;
	inv(int a = 0, int b = 0) : a(a), b(b) {}
	bool operator <(const inv &rhs) const{
		if(a == rhs.a) return b > rhs.b;
		return a < rhs.a;
	}
}S[MAXN];

int main()
{
	//freopen("2376.in", "r", stdin);
	cin>>N>>T;
	for(int i = 1; i <= N; i++)
		scanf("%d %d", &S[i].a, &S[i].b);

	sort(S + 1, S + N + 1);

	int s = 1, l = 0, ans = 0;
	for(int i = 1; i <= N; i++)
	{
		
	}
	cout<<(s >= T ? ans : -1)<<endl;
	return 0;
}