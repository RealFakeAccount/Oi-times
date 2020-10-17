#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e4 + 20;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, T; 
int a[MAXN];

priority_queue<int, vector<int>, greater<int> > q;
bool check(int x){
	for(int i = 1; i <= x; i++) q.push(a[i]);
	int t = 0, p = x + 1;
	while(!q.empty()){
		t++;
		while(!q.empty() && q.top() <= t){
			q.pop();
			if(p <= N) q.push(a[p++] + t);
		}
	}
	return t <= T;
}

int main()
{
	//freopen("p3611.in", "r", stdin);
	cin>>N>>T;
	for(int i = 1; i <= N; i++) a[i] = read();
	int l = 0, r = N;
	while(l < r){
		int mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout<<l<<endl;
	return 0;
}
