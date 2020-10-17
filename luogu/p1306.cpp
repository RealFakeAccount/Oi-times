#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e7;
const int MOD  = 1e9;

long long gcd(long long x, long long y){
	return y == 0 ? x : gcd(y, x % y);
}
long long N, M, tag;
long long f[MAXN];

int main()
{
	cin>>N>>M;
	tag = gcd(N, M);
	f[1] = f[2] = 1;
	for(int i = 3; i <= tag; i++)
		f[i] = (f[i - 1] + f[i - 2]) % MOD;
	cout<<f[tag]<<endl;
	return 0;
}
