#include <bits/stdc++.h>
using namespace std;
const int MAXL=19;
const int MAXN=21;
string in[MAXN];

bool cmp(string x,string y)
{
	return x+y>y+x;
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>in[i];
	}
	sort(in+1,in+n+1,cmp);
	for(int i=1;i<=n;i++)
		cout<<in[i];
	return 0;
}
