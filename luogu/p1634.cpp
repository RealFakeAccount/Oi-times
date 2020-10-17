#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

long long N, X, ans;

int main()
{
	cin>>X>>N; ans = 1;
	for(int i = 1; i <= N; i++) 
		ans = ans * X + ans;
	cout<<ans<<endl;
	return 0;
}