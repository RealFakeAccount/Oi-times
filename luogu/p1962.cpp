#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 1e9 + 7;
typedef long long ll;

ll N;
void mul(ll f[2], ll a[2][2]){
	ll c[2];
	memset(c, 0, sizeof(c));
	for(int j = 0; j < 2; j++)
		for(int k = 0; k < 2; k++)
			(c[j] += f[k] * a[k][j]) %= MOD;
	memcpy(f, c, sizeof(c));
}

void muls(ll a[2][2]){
	ll c[2][2];
	memset(c, 0, sizeof(c));
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			for(int k = 0; k < 2; k++) 
				(c[i][j] += a[i][k] * a[k][j]) %= MOD;
	memcpy(a, c, sizeof(c));
}

int main()
{
	cin>>N;
 	ll f[2] = {0, 1};
 	ll a[2][2] = {
 		{0, 1}, {1, 1}
 	};
 	while(N){
 		if(N & 1) mul(f, a);
 		muls(a);
 		N >>= 1;
 	}
 	cout<<f[0]<<endl;
	return 0;
}