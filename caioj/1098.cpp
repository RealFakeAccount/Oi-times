#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=500000+10;

int bit[MAXN],m,n;

int sum(int i)
{
	int a=0;
	while(i)
	{
		a+=bit[i];
		i-=i&(-i);
	}
	return a;
}

void modify(int i,int x,bool type)//1 means +,0 means-
{
	if(type==1)
	{
		while(i<=n)
		{
			bit[i]+=x;
			i+=i&(-i);
		}
		return;
	}
	if(type==0)
	{
		while(i<=n)
		{
			bit[i]-=x;
			i+=i&(-i);
		}
		return;
	}
}

int main()
{
//	freopen("1098.txt","r",stdin);
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		n+=1;
		for(int i=1; i<=n; i++)
			modify(i,1,1);
		
		int x,y,z;
		while(m--)
		{
	//		cout<<"m="<<m<<endl;
			cin>>x;
			if(x)
			{
				cin>>y>>z;
				if(sum(z)-sum(y)==z-y)
					cout<<1<<endl;
				else
					cout<<0<<endl;
			}
			if(!x)
			{
				cin>>y;
				if(sum(y+1)-sum(y)==1)
					modify(y+1,1,0);
				else
					modify(y+1,1,1);
			}
//		for(int i=1; i<=n; i++)
//			cout<<sum(i)<<" ";
//		cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
