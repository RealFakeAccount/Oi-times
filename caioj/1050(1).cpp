#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;

int s,m,n,a[10000],w[1000000],wa;
int answer[1000],ans;
int head,tail;
bool flag,fg;

void readin(int x)
{
	char c[14],b[14];
	scanf("%s",c);//如何读入字符串？？？
	for(int i=0;i<=(x-1);i++)
	{
		if(c[i]=='A')m=1+m*10;
		if(c[i]=='T')m=2+m*10;
		if(c[i]=='C')m=3+m*10;
		if(c[i]=='G')m=4+m*10;
	}
	scanf("%s",b);
	for(int i=0;i<=(x-1);i++)
	{
		if(b[i]=='A')n=1+n*10;
		if(b[i]=='T')n=2+n*10;
		if(b[i]=='C')n=3+n*10;
		if(b[i]=='G')n=4+n*10;
	}
}

void bfs()
{
	head=0;tail=1;
	int ts=1,ts1=1,ts2=1;
	for(int i=1;i<=(s-1);i++)
		ts=ts*10;
	for(int i=1;i<=(s-2);i++)
		ts1=ts1*10;
	for(int i=1;i<=(s-3);i++)
		ts2=ts2*10;
	do
	{
		head++;
		for(int i=1;i<=2;i++)
		{
			if(i==1)
			{
				int p1=a[head]/(ts);
				int p2=a[head]/(ts1)%ts2;
				int p=p2*(ts)+p1*(ts1)+a[head]%(ts1);
				for(int j=1;j<=tail;j++)
				{
					if(p==a[j])
					{
						fg=1;
						break;
					}
				}
				if(fg==0)
				{
					tail++;
					a[tail]=p;
					w[tail]=w[head]+1;
					if(a[tail]==n)
					{
						flag=1;
						break;
					}
				}
			}
			if(i==2)
			{
				int o=a[head]/(ts)+(a[head]%(ts))*10;
				for(int j=1;j<=tail;j++)
				{
					if(o==a[j])
					{
						fg=1;
						break;
					}
				}
				if(fg==0)
				{
					tail++;
					a[tail]=o;
					w[tail]=w[head]+1;
					if(a[tail]==n)
					{
						flag=1;
						break;
					}
				}
			}
			fg=0;
		}
	}while(flag==0);
	wa=w[tail];
}

int main()
{
	memset(answer,0,sizeof(answer));
	ans=1;
	while(1)
	{
		cin>>s;
		if(s==0) break;
		else
		{
			flag=0;fg=0;
			m=0;n=0;wa=0;
			memset(a,0,sizeof(a));
			memset(w,0,sizeof(w));
			readin(s);
			a[1]=m;
			if(n==m)
			{
				answer[ans]=0;
				ans++;
			}
			else
			{
				bfs();
				answer[ans]=wa;
				ans++;
			}
		}
	}
	for(int i=1;i<=(ans-1);i++)
	{
		cout<<answer[i]<<endl;
	}
	return 0;
}

