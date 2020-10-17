#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int MAXN = 5e5 + 10;

ll K, M;

inline ll calc(int x){
    int tmp = 0;
    while(x) tmp = tmp * 10 + 1, --x;
    return tmp;
}

int main()
{
	ios::sync_with_stdio(false);
    cin>>K>>M;
    for(int i = 1; i <= 30; i++){
        ll tmp = calc(i);
        if(tmp % M == K) {
            cout<<i<<endl;
            return 0;
        }
    }

	return 0;
}
