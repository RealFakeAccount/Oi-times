#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 9 + 2;

int a[MAXN], cnt[MAXN];

int main()
{
	for(int i = 1, x; i <= 6; i++){
		scanf("%d", &x);
		++cnt[x];
	}
	int flag = false;
	for(int i = 1; i <= 9; i++) if(cnt[i] >= 4) flag = cnt[i];
	if(!flag){
		cout<<"Hernia";
		return 0;
	} 
	for(int i = 1; i <= 9; i++) if(cnt[i] == 1) {
		cout<<"Bear";
		return 0;
	}
	cout<<"Elephant";
	return 0;
}