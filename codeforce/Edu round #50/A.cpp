#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N, K;

int main()
{
	cin>>N>>K;
	if(K <= N) puts("1");
	else {
		if(K % N == 0) cout<<K / N<<endl;
		else cout<<(K / N + 1)<<endl;
	}
	return 0;
}