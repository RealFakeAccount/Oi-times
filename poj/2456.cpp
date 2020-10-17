#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=100000;
const int MAXX=1000000000;
int N,C;
int x[MAXN];

bool cmp(int d)
{
	int last=0;
	for(int i=1;i<C;i++)
	{
		int crt=last+1;
		while(crt<N && x[crt]-x[last]<d)
		{
			crt++;
		}
		if(crt==N)
			return false;
		last=crt;
	}
	return true;
}

void solve()
{
	sort(x,x+N);
	int lb=0,ub=MAXX;
	while(ub-lb>1)
	{
		int mid=(lb+ub)/2;
		if(cmp(mid))
			lb=mid;
		else
			ub=mid;
	}
	printf("%d\n",lb);
}

int main()
{
	scanf("%d%d",&N,&C);
	for(int i=0;i<N;i++)
		scanf("%d",&x[i]);
	solve();
	return 0;
}

