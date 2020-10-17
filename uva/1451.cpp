#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 20;

int sum[MAXN], q[MAXN];
int N, L;

double calc(int a, int b)
{
	return ((double) sum[b] - sum[a]) / (b - a);
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--)
	{
		cin>>N>>L;
		string str;
		cin>>str;
		memset(sum, 0, sizeof(sum));
		memset(q, 0, sizeof(q));
		for(int i = 1; i <= N; i++)
			sum[i] = sum[i - 1] + str[i - 1] - '0';
		int head = -1, tail = -1;
		double ans = 0;
		int s = 0, e = L, len = 0;
		for(int t = L; t <= N; t++)
		{
			int j = t - L; 
			while(head < tail && calc(q[tail], j) <= calc(q[tail - 1], q[tail])) --tail;
			q[++tail] = j;
			while(head < tail && calc(q[head + 1], t) <= calc(q[head], t)) ++head;
			double tmp = calc(q[head], t);
			int l = t - q[head] + 1;
			if(tmp > ans || (tmp == ans && l < len))
			{
				ans = tmp;
				len = l;
				s = q[head];
				e = t;
			}
		}
		cout<<s + 1<<" "<<e<<endl;
	}
	return 0;
}

inline double calc(int a, int b)
{
	
}

for(int i = 1; i <= N; i++)
	sum[i] = sum[i - 1] + str[i - 1] -'0';

for(int t = L; t <= N; t++)
{
	int s = t - L + 1;
	while(head < tail && )
}