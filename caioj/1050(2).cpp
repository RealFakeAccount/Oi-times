#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int s,m,n,a[10000],w;
int head,tail;
bool flag;

void readin(int x)
{
	char c[13],b[13];
	for(int i=1;i<=x;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=x;i++)
	{
		if(c[i]=='A')m=1+m*10;
		if(c[i]=='T')m=2+m*10;
		if(c[i]=='C')m=3+m*10;
		if(c[i]=='G')m=4+m*10;
	}
	for(int i=1;i<=x;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=x;i++)
	{
		if(b[i]=='A')n=1+n*10;
		if(b[i]=='T')n=2+n*10;
		if(b[i]=='C')n=3+n*10;
		if(b[i]=='G')n=4+n*10;
	}
}

int bfs()
{
	head=0;tail=1;
	do
	{
		head++;
		for(int i=1;i<=2;i++)
		{
			if(i==1)
			{
				int p1=a[head]/(s*10);
				int p2=a[head]/((s-1)*10);
				int p=p2/(s*10)+p1/((s-1)*10)+a[head]%((s-2)*10);
				for(int j=1;j<=tail;j++)
				{
					if(p==a[j])
						break;
					else
					{
						tail++;
						w++;
						a[tail]=p;
						if(a[tail]==n)
						{
							flag=1;
							break;
						}
					}
				}
			}
			if(i==2)
			{
				int o=a[head]/(s*10)+a[head]%(s*10)*10;
				for(int j=1;j<=tail;j++)
				{
					if(o==a[j])
						break;
					else
					{
						tail++;
						w++;
						a[tail]=o;
						if(a[tail]==n)
						{
							flag=1;
							break;
						}
					}
				}
			}
			
		}
	}while(flag==0);
}

int main()
{
	while(1)
	{
		cin>>s;
		if(s==0) break;
		else
		{
			flag=0;w=0;
			m=0;n=0;
			memset(a,0,sizeof(a));
			readin(s);
			bfs();
			cout<<w<<endl;
		}
	}
	return 0;
}

