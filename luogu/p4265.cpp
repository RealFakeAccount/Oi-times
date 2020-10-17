#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 250 + 5;
typedef pair<int, int> P;

int N, B;
int f[MAXN], s[MAXN], d[MAXN];
int g[MAXN];

int main()
{
	cin>>N>>B;
	for(int i = 1; i <= N; i++) scanf("%d", &f[i]);
	for(int i = 1; i <= B; i++)
		scanf("%d%d", &s[i], &d[i]);
	g[1] = true;
	for(int i = 1; i <= B; i++){
		for(int j = 1; j <= N; j++){
			if(g[j] && s[i] >= f[j]){
				for(int k = j; k <= min(j + d[i], N); k++) if(s[i] >= f[k])
					g[k] |= 1;
			}
		}
		if(g[N]){
			printf("%d", i - 1);break;
		}
	}
	return 0;
}