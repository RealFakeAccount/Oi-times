#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

int A, B, C;

int main()
{
	cin>>A>>B>>C;
	int ans = (1 << 30);
	int a = A, b = B, c = C, tmp = 0;
	if(a + b < c && a + c < b && b + c < a) return puts("0"), 0;
	if(a < B + C) {
		while(!(a + B > C && a + C > B)) ++a, ++tmp;
		ans = min(ans, tmp); tmp = 0;
	}
	

	if(b < A + C) {
		while(!(b + A > C && b + C > A)) ++b, ++tmp;
		ans = min(ans, tmp); tmp = 0;
	}

	if(c < A + B) {
		while(!(c + A > B && c + B > A)) ++c, ++tmp;
		ans = min(ans, tmp);
	}

	printf("%d\n", ans);
	return 0;
}