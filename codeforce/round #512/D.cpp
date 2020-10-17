#include <cmath>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int N, M, K;

int main()
{
	cin>>N>>M>>K;
	bool flag = false;
	if(K == 1) flag = true;
	if(((1LL * N * M * 2) % K)) flag = true;

	if(!flag) {
		flag = true;
		ll res = N * M * 2 / K;
		for(int i = 1; i <= N; i++){
			if(res % i == 0) {
				int x = i;
				if(res / 1LL * x <= 1LL * M){
					puts("YES");
					cout<<x<<" "<<0<<endl;
					cout<<0<<" "<<0<<endl;
					cout<<0<<" "<<res / x<<endl;
					flag = false; break;
				}
			} 
		} 
	}
	if(flag) puts("NO");
	return 0;
}