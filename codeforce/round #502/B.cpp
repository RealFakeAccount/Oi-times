#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 2e5 + 20;
typedef long long ll;
int N;
string a, b;

int main()
{
	ios::sync_with_stdio(false);
	cin>>N;
	cin>>a>>b;
	ll sum0[2] = {0}, sum1[2] = {0};
	ll ans = 0;
	for(int i = 0; i < N; i++){
		if(b[i] == '0') {
			if(a[i] == '1') ans += sum1[0] + sum0[0];
			else ans += sum1[1] + sum0[1];
			sum0[1] += a[i] == '1';
			sum0[0] += a[i] == '0';
		}
		else {
			if(a[i] == '1') ans += sum0[0];
			else ans += sum0[1];
			sum1[0] += a[i] == '0';
			sum1[1] += a[i] == '1';
		}
	}
	cout<<ans<<endl;
	return 0;
}