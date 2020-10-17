#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 20;
const int MOD = 1e9 + 7;
typedef long long ll;
int N, K;

void putdouble(double x){
	cout<<(ll)(x * MOD) % MOD + 1<<endl;
}

int main()
{
	cin>>N>>K;
	double ans = 1 / (1.0 * N);
	for(int i = N; i >= 2; i--){
		if(i <= K + 1){}
			
	}
	putdouble(ans);
	return 0;
}