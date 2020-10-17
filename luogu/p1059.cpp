#include <bits/stdc++.h>
using namespace std;

bool vis[1001];

int main()
{
	ios::sync_with_stdio(false);
	int n;cin>>n;
	int x,cnt=0;
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(!vis[x])
		{
			vis[x]=true;
			cnt++;
		}
		
	}
	cout<<cnt<<endl;
	for(int i=1;i<=1001;i++)
		if(vis[i])	
			cout<<i<<" ";
	return 0;
}
