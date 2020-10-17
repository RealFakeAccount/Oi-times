#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 5e7 + 20;

int N, s;

inline int calc(int x){
	while(x % 2 == 0) s++, x /= 2;
	while(x % 5 == 0) s--, x /= 5;
	return x;
}

int main()
{
	cin>>N;
	int tmp = 1;
	for(int i = 2; i <= N; i++) tmp = (tmp * calc(i)) % 10;
	for(int i = 1; i <= s; i++) tmp = (tmp * 2) % 10;
	cout<<tmp<<endl;
	return 0;
}
