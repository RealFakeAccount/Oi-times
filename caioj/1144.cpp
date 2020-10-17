#include <bits/stdc++.h>
using namespace std;
const int MAXN=100000+5;

long long f[MAXN];

bool cmp(long long &x,long long &y)
{
	return x<y ? true : false;
}

int main()
{
	ios::sync_with_stdio(false);
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>f[i];
		
	sort(f,f+N,cmp);
	
	for(int i=0;i<N;i++)
		cout<<f[i]<<endl;
	return 0;
}
