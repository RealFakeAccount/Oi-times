#include<cstdio>
#include<cstring>
using namespace std;
struct node
{
	int a[4][4],x,y,dep;
};
node list[401000];
const int dx[4]={0,-1,0,1};
const int dy[4]={-1,0,1,0};
int head,tail;
bool myhash[400000];
int d[11];
int kangtuo(node tno)
{
	int a[10],L,k;
	L=0;
	for(int i=1;i<=3;i++)
	{
		for (int j=1;j<=3;j++)
		{
			L++;
			a[L]=tno.a[i][j]+1;
		}
	}
	bool bo[10];
	memset(bo,false,sizeof(bo));
	int sum=0;
	for(int i=1;i<=8;i++)
	{
		k=0;
		for(int j=1;j<a[i];j++)
		{
			if(bo[j]==false)
				k++;
		}
		sum=sum+k*d[9-i];
		bo[a[i]]=true;
	}
	return sum+1;
}
int main()
{
	d[0]=1;for(int i=1;i<=9;i++) d[i]=d[i-1]*i;
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&list[1].a[i][j]);
				if(list[1].a[i][j]==0)
				{
					list[1].x=i;
					list[1].y=j;
				}
			}
		list[1].dep=1;
			
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&list[0].a[i][j]);
			}
		int ed=kangtuo(list[0]);
			
		head=tail=1;
		memset(myhash,false,sizeof(myhash));
		bool bk=false;
		while(head<=tail)
		{
			for(int i=0;i<=3;i++)
			{
				node tno=list[head];
				tno.x=list[head].x+dx[i];
				tno.y=list[head].y+dy[i];
				if(tno.x>=1&&tno.x<=3&&tno.y>=1&&tno.y<=3)
				{
					int tt=tno.a[tno.x][tno.y];
					tno.a[tno.x][tno.y]=tno.a[list[head].x][list[head].y];
					tno.a[list[head].x][list[head].y]=tt;
					int k=kangtuo(tno);
					tno.dep=list[head].dep+1;
					if(myhash[k]==false)
					{
						myhash[k]=true;
						tail++;list[tail]=tno;
						if(k==ed)
						{
							printf("%d\n",tno.dep);
							bk=true;
							break;
						}
					}
				}
			}
			if(bk==true)break;
			head++;
		}	
		return 0;
}
