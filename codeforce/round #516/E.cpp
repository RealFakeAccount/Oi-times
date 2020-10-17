#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 30;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N;
string col;

int main()
{
	cin>>N;
	int l = 0, r = 1e9;
	cout<<"0 0"<<endl;
	while(N--) {
		cin>>col;
		int mid = (l + r) >> 1;
		if(col == "black") l = mid;
		else r = mid;
		cout<<mid<<" "<<mid<<endl;
	}
	cout<<l<<" "<<l + 1<<" "<<l + 1<<" "<<l<<endl;
	return 0;
}