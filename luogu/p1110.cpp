#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int inf=10e4;
const int infnity=9*10e8;
int a[inf]={0};
int dp[inf]={0};
int n;
int lis()
{
    fill(dp,dp+inf,infnity);
    for(int i=0;i<n;i++)
    {
        *upper_bound(dp,dp+n,a[i])=a[i];
    }
    return (lower_bound(dp,dp+n,infnity)-dp);
}
int main()
{
//	freopen("line.in","r",stdin);
//	freopen("line.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int ans1=n-lis();
    reverse(a,a+n);
    int ans2=n-lis();
    printf("%d\n",min(ans1,ans2));
    return 0;
}

