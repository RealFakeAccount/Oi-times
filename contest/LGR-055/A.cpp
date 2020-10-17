#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

int M;
long long f[3];

int main()
{
	cin>>M;
	f[0] = 0, f[1] = 1;
	int p = 0;
	while(true) {
		if(p && f[p % 3] % M == 0 && f[(p + 1) % 3] % M == 1) {
			printf("%d\n", p); break;
		}
		f[(p + 2) % 3] = (f[p % 3] + f[(p + 1) % 3]) % M; ++p;
	}	
	return 0;
}
