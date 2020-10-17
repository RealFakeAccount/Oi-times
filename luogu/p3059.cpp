#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 5e4 + 10;
const int MAXK = 10 + 1;

int K, N;
int ch[MAXK][MAXN];
int sum[MAXK][MAXN]
map<int, int> pos;


int main()
{
	cin>>K>>N;
	for(int i = 1; i <= K; i++){
		scanf(" ");
		for(int j = 1; j <= N; j++)
			ch[i][j] = (getchar() == '(' ? 1 : -1);
	}
	for(int i = 1; i <= K; i++)
		for(int j = 1; j <= N; j++) 
			sum[i][j] = sum[i][j - 1] + ch[i][j];
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= K; j++){

		}
	}
	return 0;
}