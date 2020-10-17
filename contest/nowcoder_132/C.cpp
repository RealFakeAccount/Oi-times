#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
const int MAXN = 1e2 + 20;

int N;
bool vis[MAXN * MAXN * MAXN];
int tmp[2][MAXN * MAXN * MAXN];
int p[2];

int main()
{
	cin>>N;
	int d = 0; int l, r;
	scanf("%d%d", &l, &r);
	for(int i = l; i <= r; i++){
		vis[i * i] = true;
		tmp[d][p[d]++] = i * i;
	}
	for(int i = 2; i <= N; i++){
		scanf("%d%d", &l, &r);
		p[d ^ 1] = 0; memset(vis, false, sizeof(vis));
		for(int j = l; j <= r; j++){
			for(int k = 0; k < p[d]; ++k){
				if(!vis[ tmp[d][k] + j * j ]){
					vis[ tmp[d][k] + j * j ] = true;
					tmp[d ^ 1][p[d ^ 1]++] = tmp[d][k] + j * j;
				}
				else cout<<tmp[d][k] + j * j<<endl;
			}
		}

		d ^= 1;for(int i = 0; i < p[d]; i++)
		cout<<tmp[d][i]<<" ";
		cout<<endl;
	}
	for(int i = 0; i < p[d]; i++)
		cout<<tmp[d][i]<<" ";
	return 0;
}
