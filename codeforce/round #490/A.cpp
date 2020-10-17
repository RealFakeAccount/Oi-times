#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 1e2 + 20;
const int INF = 0x3f3f3f3f;
int a[MAXN];
int N, K;

int main()
{
	cin>>N>>K;
	for(int i = 1; i <= N; i++) scanf("%d", &a[i]);
		a[0] = a[N + 1] = INF;
	int l = 0, r = N + 1;
	while(a[l + 1] <= K) l++;
	while(a[r - 1] <= K) r--;
	if(r <= l) cout<<N<<endl;
	else cout<<((N - r + 1) + (l))<<endl;	
	return 0;
}