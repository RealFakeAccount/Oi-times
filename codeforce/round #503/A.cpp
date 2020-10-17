#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e8 + 20;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, H, A, B, K;

inline int calc(int x){
	if(A <= x && x <= B) return 0;
	else if(x < A) return A - x;
	else return x - B;
}

int main()
{
	cin>>N>>H>>A>>B>>K;
	while(K--){
		int ta = read(), fa = read(), tb = read(), fb = read();
		if(ta == tb) cout<<abs(fa - fb)<<endl;
		else {
			int ans = 0;
			ans += abs(ta - tb);
			if(fa > B && fb > B) ans += (fa - B) + (fb - B);
			else if(fa < A && fb < A) ans += (A - fa) + (A - fb);
			else ans += abs(fa - fb);
			cout<<ans<<endl;
		}
	}
	return 0;
}