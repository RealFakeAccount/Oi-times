#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
const int dx[4]={ -1,0,1,0};
const int dy[4]={ 0,1,0,-1 };
struct node
{
    int x,y,dep;
};
node list[1110000];
int head,tail;
bool map[1010][1010];
int k1[2001];
int main()
{
    int n,m,k,i,j,x1,x2,y1,y2;
    scanf("%d%d",&n,&m);
    scanf("\n");
    memset(map,false,sizeof(map));
    char cc;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%c",&cc);
            if( cc=='1') map[i][j]=true;
            else  if( cc=='0') map[i][j]=false;
        }
        scanf("\n");
    }
	scanf("%d",&k);
	for(int o=1;o<=k;o++)
	{
		memset(list,0,sizeof(list));
		scanf("%d%d%d%d",&list[1].x,&list[1].y,&list[0].x,&list[0].y);
		list[1].dep=0;
		bool bk=false;
		head=1;tail=1;
		while(head<=tail)
		{
			for(i=0;i<=3;i++)
			{
				node tno=list[head];
				tno.x=list[head].x+dx[i]; tno.y=list[head].y+dy[i];
				if( map[ tno.x][ tno.y]==true)
				{
					map[tno.x][tno.y]=false;
					tno.dep=list[head].dep+1;
					list[++tail]=tno;
					if( list[tail].x==list[0].x && list[tail].y==list[0].y)
					{
						bk=true;
						k1[o]=list[tail].dep;
						break;
					}
				}
			}
			if(bk==true) break;
			head++;
		}
		if( bk==false)  k1[o]=-1;
	}
	for(int o=1;o<=k;o++)
	{
		if(k1[o]==-1)
		{
			printf("Impossible\n");
		}
		else
		{
			printf("%d\n",k1[o]);
		}
	}
	return 0;
}