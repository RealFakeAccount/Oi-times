#include <cstdio>
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
double dfs(double x,double y,int k)
{
	if(k==1) return max(x,y)/min(x,y);
	double ans=999999;
	for(int i=1;i<k;i++)
	{
		ans=min(ans,max(dfs(x,y/k*i,i),dfs(x,y/k*(k-i),k-i)));
	}
	for(int i=1;i<k;i++)
	{
		ans=min(ans,max(dfs(x/k*i,y,i),dfs(x/k*(k-i),y,k-i)));		
	}
	return ans;
}
int main()
{
	double x,y;
	int k;
	cin>>x>>y>>k;
	double d=dfs(x,y,k);
	cout<<setiosflags(ios::fixed)<<setprecision(6)<<d<<endl;
}