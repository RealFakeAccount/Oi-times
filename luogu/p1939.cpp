#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 1e9 + 7;
typedef long long ll;

int T; ll N;

void mul(ll a[3], ll f[3][3]){
	ll c[3];
	memset(c, 0, sizeof(c));
	for(int i = 0; i < 3; i++)
		for(int k = 0; k < 3; k++)
			(c[i] += a[k] * f[i][k]) %= MOD;
	memcpy(a, c, sizeof(c));
}

void muls(ll f[3][3]){
	ll c[3][3];
	memset(c, 0, sizeof(c));
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			for(int k = 0; k < 3; k++)
				(c[i][j] += f[i][k] * f[k][j]) %= MOD;
	memcpy(f, c, sizeof(c));
}

int main()
{
	cin>>T;
	while(T--){
		cin>>N;
		ll a[3] = {1, 1, 1};
		ll f[3][3] = {
			{1, 1, 0},
			{0, 0, 1},
			{1, 0, 0}
		};
		if(N <= 3){
			puts("1"); continue;
		}
		N -= 2;
		while(N){
			if(N & 1) mul(a, f);
			muls(f);
			N >>= 1;
		}
		cout<<a[2]<<endl;
	}
	return 0;
}