#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll x, ll y)
{
	return y ? gcd(y, x % y) : x;
}

ll P, Q, B, tmp;

int main()
{
	ios::sync_with_stdio(false);	
	int T; cin>>T;
	while(T--, T > -1)
	{
		cin>>P>>Q>>B;
		ll p = gcd(P, Q);
		Q /= p;

		while((tmp = gcd(Q, B)) != 1)
			while(Q % tmp == 0) Q /= tmp;
		puts(Q == 1 ? "Finite" : "Infinite");
	}

	return 0;
}