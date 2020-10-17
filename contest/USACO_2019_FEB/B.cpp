#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, a[500019];

int stamin[500019],staok[500019],stamax[500019]; 

int maxnum=0,bottom[500019],maxx; 

int main(){
	freopen("dishes.in", "r", stdin);
	freopen("dishes.out", "w", stdout);
    int pit = 0; cin>>N;
    for(int i = 1; i <= N; i++) a[i] = read();
    for(int i = 1;i <= N; i++){ //不断向栈中加元素
        if(maxx < a[i]) { 
        	maxx = a[i], bottom[++pit] = a[i]; 
        	continue; 
        } //是否要开新栈
        int stanum = lower_bound(bottom + 1, bottom + pit + 1, a[i]) - bottom + 1; //属于的栈的编号
        if(maxnum > stanum) return printf("%d\n", i - 1), 0;
        if(staok[stanum] == 1 && a[i] < stamax[stanum])
        	return printf("%d\n", i - 1), 0;
        if(staok[stanum] == 1) stamax[stanum] = a[i]; 
        if(a[i] > stamin[stanum])
        	staok[stanum] = 1, maxnum = max(maxnum, stanum);
        stamin[stanum] = min(stamin[stanum], a[i]);
    } 
    printf("%d\n", N);
    return 0;
}