#include <cstdio>
#include <cstring>
using namespace std;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
//下右上左
int a[20][20];

int main()
{
	int x,y,n,i,j,t,k,g,h;
	scanf("%d",&n);
	memset(a,-1,sizeof(a));
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			a[i][j]=0;
		}
	}
	x=1;y=1;k=1;t=0;
	while(k<=n*n)
	{
		a[x][y]=k;
		k++;
		
		if(a[x+dx[t]][y+dy[t]]!=0)
		{
			t++;
			if(t==4)
			{
				t=0;
			}
		}
		
		x=x+dx[t];
		y=y+dy[t];
	}
	for(g=1;g<=n;g++)
	{
		for(h=1;h<=n;h++)
		{
			printf("%4d",a[g][h]);
		}
		printf("\n");
	}
	return 0;
}
