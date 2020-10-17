#include <bits/stdc++.h>
using namespace std;
const int MAXN=500000+5;
typedef long long LL;
LL bitr[MAXN*2];
int n;

 LL lowbit(LL t)
 {
	return t&(-t);
 }
 void add(LL k,LL num)
{
	while(k<=n)
	{
		bitr[k]+=num;
		k+=k&-k;
	}
}
 
 LL getsum(LL x)
 {
 	LL ans=0;
 	for(LL i=x;i>0;i-=lowbit(i))
 		ans+=bitr[i];
 	return ans;
 }
 
 int main()
 {
 	ios::sync_with_stdio(false);
 	int m;
 	cin>>n>>m;
 	LL j;
 	for(LL i=1;i<=n;i++)
 	{
 		cin>>j;
 		add(i,j);
	 }
 	LL x,y,z;
 	for(int i=1;i<=m;i++)
	{
 		cin>>x>>y>>z;
 		if(x==1)
 			add(y,z);
 		else
 			cout<<getsum(z)-getsum(y-1)<<endl;
	}
	return 0;
 }
