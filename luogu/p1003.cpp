#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXS=100000+10;
const int MAXN=10000+10;
typedef pair<int,int> P;
struct size
{
	P p;
	int lx,ly;
	size(P in,int u=0,int v=0) : p(in),lx(u),ly(v) {}
};

size carpet[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int a,b,g,k;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>g>>k;
		carpet[i]( size(P(a,b),g,k) );
	}
	P ans;int x,y;
	cin>>x>>y;
	ans=(x,y);
	
	return 0;
}
