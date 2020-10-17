#include<cstring>
#include<cstdio>
using namespace std;
int ma,mb,mc,k;                            //最大容量以及目标油量
int a,b,c,ans;                               //记录当前油量，以及操作步数
int agb(a,b)               //ma瓶多少油，mb瓶多少油
{
	for(int i=1;i<=a;i++)
	{
		if(b<mb)
		{
			a--;
			b++;
		}
	}
}
int agc(a,c)     
{
	for(int i=1;i<=a;i++)
	{
		if(c<mc)
		{
			a--;
			c++;
		}
	}
}
int bga(b,a)     
{
	for(int i=1;i<=b;i++)
	{
		if(a<ma)
		{
			b--;
			a++;
		}
	}
}
int bgc(b,c)     
{
	for(int i=1;i<=b;i++)
	{
		if(c<mc)
		{
			b--;
			c++;
		}
	}
}
int cga(c,a)     
{
	for(int i=1;i<=c;i++)
	{
		if(a<ma)
		{
			c--;
			a++;
		}
	}
}
int cgb(c,b)     
{
	for(int i=1;i<=c;i++)
	{
		if(b<mb)
		{
			b--;
			a++;
		}
	}
}
int daoyou(int m,int n,int nmax)
{
	for(int i=1;i<=m;i++)
	{
		if(n<nmax)
		{
			m--;
			n++;
		}
	}
}
int main()
{ 
	cin>>a>>b>>c>>k;
	
	return 0; 
} 