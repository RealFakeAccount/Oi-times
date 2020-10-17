#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
const int MAXN=5000+10;
int N;
bool f[MAXN],d[MAXN];//front:true ; back:false

void readin(int i)
{
	char x;
	cin>>x;
	if(x=='F')
		f[i]=true;
	else
		f[i]=false;
	//cout<<"done"<<endl;
	return;
}

void ope(int s,int k)
{
	for(int i=1;i<=k;i++)
	{
		if(d[s+i-1])
			d[s+i-1]=false;
		else
			d[s+i-1]=true;
	}
}
int solve(int k)
{
	int cnt=0;
	for(int i=1;i<=N;i++)
		d[i]=f[i];
	for(int i=1;i<=N;i++)
	{
		if(!d[i])
		{
			ope(i,k);
			cnt++;
		}
		if(i+k-1==N)
		{
			for(int j=i;j<=N;j++)
				if(!d[j])
					return MAXN;
			return cnt;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>N;
	for(int i=1;i<=N;i++)
		readin(i);
	
	pair<int,int> ans;int a;
	ans.first=MAXN;
	for(int i=1;i<=N;i++)
	{
		a=solve(i);
		if(a<ans.first)
		{
			ans.first=a;
			ans.second=i;
		}
	}
	cout<<ans.first<<" "<<ans.second<<endl;
	return 0;
}
