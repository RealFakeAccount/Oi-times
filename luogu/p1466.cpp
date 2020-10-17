#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
const int MAXN = 40;

int N, M;
long long f[800];

int main()
{
	cin>>N;
	M = (N + 1) * N / 2;
	if(M & 1) {
		puts("0"); return 0;
	}
	M /= 2;
	f[0] = 1;
	for(int i = 1; i <= N; i++)
		for(int j = M; j >= i; j--)
			f[j] += f[j - i];
	cout<<f[M] / 2<<endl;
	return 0;
}