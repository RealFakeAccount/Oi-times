#include <cmath>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll a, b;

ll msqrt(ll x){
	for(ll i = 0; i <= x; i++){
		if(i * i >= x) return i;
	}
	return 1;
}

int main()
{
	cin>>a>>b;

	ll sum = a + b;
	ll tmp = 0; ll m = msqrt(sum);
	for(ll i = m; i; i--) if(sum % i == 0){
		tmp = i; break;
	}
	cout<<((tmp + sum / tmp) << 1)<<endl;
	return 0;
}