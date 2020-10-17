#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXL=100000;
const int MAXN=10000;
int N,K;
double L[MAXN];
bool cmp(double x)
{
	int num=0;
	for( int i=0;i<N;i++)
		num+=(int) (L[i]/x);
	return num>=K;
}
void solve()
{
	double lb=0,ub=MAXL;
	for( int i=0;i<100;i++)
	{
		double mid=(lb+ub)/2;
		if(cmp(mid))
			lb=mid;
		else
			ub=mid;
	}
	printf("%.2f\n",floor(ub*100)/100);
}
int main()
{
	scanf("%d%d",&N,&K);
	for( int i=0;i<N;i++)
		scanf("%lf",&L[i]);
	solve();
	return 0;
}
