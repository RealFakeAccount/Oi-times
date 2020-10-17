#include <algorithm>//STL 通用算法
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <sstream>
using namespace std;

int dp[100];
int a[5]={4,2,3,1,5};
int n=5;

int main()
{
	fill(dp,dp+n,255);
	for (int i=0;i<n;i++)
		*lower_bound(dp,dp+n,a[i])=a[i];
	printf("%d\n",lower_bound(dp,dp+n,255)-dp);
}
