#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 20;

inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

struct seg
{
	int l, r, num;
	seg(int l = 0, int r = 0, int  n = 0) : l(l), r(r), num(n) {}
	bool operator <(const seg &rhs) const{
		if(l == rhs.l) return r > rhs.r;
		return l < rhs.l;
	}
}s[MAXN];

int N;

int main()
{
	cin>>N;

	int l, r;
	for(int i = 1; i <= N; i++)
	{
		l = read(), r = read();
		s[i] = seg(l, r, i); 
	}

	sort(s + 1, s + N + 1);

	int last = 0;
	for(int i = 1; i <= N; i++)
	{
		if(last >= s[i].r)
		{
			cout<<s[i].num<<" "<<s[i - 1].num<<endl;
			return 0;
		}
		last = s[i].r;
	}
	cout<<-1<<" "<<-1<<endl;
	return 0;
}