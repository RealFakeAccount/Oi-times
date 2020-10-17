#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
struct node
{
	char a[15];
	int s;
}q[1000];
int n;
int head,tail;
char t;
char x[15],tx[15];
bool flag=0;
int main()
{
	for(1)
	{
		scanf("%d",&n);
		if(n==0)
		{
			break;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				scanf("%c",&x[i]);
			}
			for(int i=1;i<=n;i++)
			{
				scanf("%c",&tx[i]);
			}
			memset(q,0,sizeof(q));
			head=0;tail=1;
			for(int i=1;i<=n;i++)
				q[1].a[i]=x[i];
			do
			{
				head++;
				for(int i=1;i<=2;i++)
				{
					if(i==1)
					{
						t=q[head].a[1];
						q[head].a[1]=q[head].a[2];
						q[head].a[2]=t;
						for(int j=1;j<=tail;j++)
						{
							if(q[])
						}
					}
				}
			}
		}
	}
	return 0;
}
