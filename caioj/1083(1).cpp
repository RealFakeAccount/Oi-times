#include<iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>//STL 通用算法
using namespace std;

struct node
{
	int wi,li;
}part[210000];

bool b[210000];
int n,anss=0;

bool cmp(node x,node y)
{
	if(x.wi<y.wi)
		return true;
	if(x.wi>y.wi)
		return false;
	return false;
}

int main()
{
	//freopen("1083.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>part[i].li>>part[i].wi;
	sort(part+1,part+n+1,cmp);
	//for(int i=1;i<=n;i++)
	//{cout<<"i="<<i<<endl;
	//	cout<<part[i].li<<" "<<part[i].wi<<endl;}
	memset(b,true,sizeof(b));
	while(true)
	{
		bool bk=false;int p=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i])
				bk=true;
			if(b[i] && part[i].li>=p)
			{
				b[i]=false;
				p=part[i].li;
			}
		}
		if(bk==false)
			break;
		anss++;
	}
	cout<<anss<<endl;
	return 0;
}
