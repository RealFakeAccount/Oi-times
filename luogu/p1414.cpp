#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 1e4 + 20;
const int MAXM = 1e6 + 20;

int N, a[MAXN];
int vis[MAXM], cnt[MAXM];//至少出现N次的约数

inline void calc(int x){
	for(int i = 1; i * i <= x; i++){
		if(x % i == 0) {
			++vis[i];
			if(x / i != i) ++vis[x / i];
		}
	}
}


int main()
{
	cin>>N;
	for(int i = 1; i <= N; i++){
		scanf("%d", &a[i]);
		calc(a[i]);
	}
	
	int p = MAXM - 1;
	for (int i = 1; i <= N; i++)
    {
        while (vis[p] < i) p--;
        cout << p << endl;
    }
	return 0;
}