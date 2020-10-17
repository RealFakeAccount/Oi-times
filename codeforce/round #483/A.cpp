#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 1e3 + 20;

int a[MAXN], N;

int main()
{
	cin>>N;
	for(int i = 1; i <= N; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + N + 1);
	
	if(N % 2 == 0) cout<<a[(N / 2)]<<endl;
	else cout<<a[(N + 1) / 2]<<endl;
	return 0;
}