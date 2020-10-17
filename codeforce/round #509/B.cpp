#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){ return a == 0 ? b : gcd(b % a, a); } 
ll A, B, X, Y;

int main()
{
	cin>>A>>B>>X>>Y;
	ll tmp = gcd(X, Y);
	X /= tmp, Y /= tmp;
	if(A == 0 || B == 0) puts("0");
	else cout<<min(A / X, B / Y)<<endl;
	return 0;
}