#include<cstdio>
#include<cstring>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
struct node
{
	int x,y,a[4][4],dep;
}list[1000000],st,ed;
int head,tail;
bool bijiao(node p1,node p2)
{
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			if(p1.a[i][j]!=p2.a[i][j])
				return false;
		}
	}
	return true;
}
bool panchong(node tno)
{
	for(int i=1;i<=tail;i++)
	{
		if(bijiao(tno,list[i]))
			return true;
	}
}
int main()
{
	for (int i=1;i<=3;i++)
	{
		for (int j=1;j<=3;j++)
		{
			scanf("%d",&st.a[i][j]);
			if(st.a[i][j]==0)
			{
				st.x=i;st.y=j;
			}
		}
	}
	st.dep=1;
	
	for (int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
			scanf("%d",&ed.a[i][j]);
	}
	list[1]=st;head=tail=1;
	bool bk=false;
	while(head<=tail)
	{
		int x=list[head].x,y=list[head].y;
		for(int i=0;i<=3;i++)
		{
			int tx=x+dx[i],ty=y+dy[i];
			if(tx>=1&&tx<=3&&ty>=1&&ty<=3)
			{
				node tno=list[head];
				tno.dep=list[head].dep+1;
				tno.x=tx;tno.y=ty;
				
				int t=tno.a[x][y];tno.a[x][y]=tno.a[tx][ty];tno.a[tx][ty]=t;
				
				if(panchong(tno)==true)
					continue;
				tail++;list[tail]=tno;
				if(bijiao(list[tail],ed)==true)
				{
					printf("%d\n",list[tail].dep);
					return 0;
				}
			}
			head++;
		}
		return 0;
	}
}
