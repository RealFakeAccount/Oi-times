#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

long long L, R;

int main()
{
	ios::sync_with_stdio(false);
	cin>>L>>R; cout<<"YES"<<endl;
	for(long long i = L; i < R; i += 2)
		cout<<i<<" "<<i + 1<<endl;
	return 0;
}