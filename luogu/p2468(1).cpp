#include <bits/stdc++.h>
using namespace std;
const int MAXR=200+5;
const int MAXP=10+1;
const int MAXN=5e5+5;



int R,C,M;

namespace opt1
{
	#define mid (( (L) + (R) ) >>1 )
	int B[MAXR][MAXR];
	int siz[MAXR][MAXR][MAXP],sum[MAXR][MAXR][MAXP];//siz[i][j][k]:[i][j]中>=k的数的个数;
													//sum[i][j][k]:[i][j]中>=k的数的和

	void init1()
	{
		for(int i=1; i<=R; i++)
			for(int j=1; j<=C; j++)
				scanf("%d", &B[i][j]);

		for(int i=1; i<=R; i++)
			for(int j=1; j<=C; j++)
				for(int k=1; k<=MAXP; k++)
				{
					siz[i][j][k] = siz[i-1][j][k] + siz[i][j-1][k] - siz[i-1][j-1][k];
					sum[i][j][k] = sum[i-1][j][k] + sum[i][j-1][k] - sum[i-1][j-1][k];

					if(B[i][j] >= k)
						siz[i][j][k]++,sum[i][j][k] += B[i][j];
				}
	}

	void work1()
	{

		int x1,x2,y1,y2,h;
		while(M--)
		{
			scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&h);

			int L=0,R=MAXP;
			x1--,y1--;

			while(R > L+1)
			{
				if(sum[x1][y1][mid] + sum[x2][y2][mid] - sum[x1][y2][mid] - sum[x2][y1][mid] >=h)
					L=mid;
				else R=mid;
			}

			if(L==0) puts("Poor QLW");
			else
			{
				int ans1=sum[x1][y1][mid] + sum[x2][y2][mid] - sum[x1][y2][mid] - sum[x2][y1][mid]-h;
				int ans2=siz[x1][y1][mid] + siz[x2][y2][mid] - siz[x1][y2][mid] - siz[x2][y1][mid];
				printf("%d\n",ans2-ans1/L);
			}
		}
	}
	#undef mid
}

namespace opt2
{
	#define mid (((l) + (r)) >>1 )
	inline int read()
	{
		int x;
		scanf("%d",&x);
		return x;
	}

	int B[MAXN],S[MAXN];

	struct node *null;
	struct node 
	{
		node *rs,*ls;
		int sum,siz;//siz:>=k的数的个数;
					//sum:>=k的数的和
		node() : rs(null),ls(null),sum(0),siz(0) {}
		inline void maintain()
		{
			sum = ls->sum + rs->sum;
			siz = ls->siz + rs->siz;
		}
	}*root[MAXP],pool[MAXP<<5];

	inline node *newnode()
	{
		static int cnt=0;
		if( cnt < (MAXP<<5) )
			return &pool[cnt++];
		else
		 return new node;
	}

	node *modify(const node *o,int l,int r,int v)
	{
		if(l > r) return null;

		node *now=newnode();
		*now = *o;

		if(l == r) 
		{
			now->siz++,now->sum=v*now->siz;
			return now;
		}
		else
		{
			if(v<=mid) now->ls = modify(now->ls, l, mid, v);
			else now->rs = modify(now->rs, mid+1, r, v);
		}
		now->maintain();
		return now;
	}

	int querysum(node *a,node *b,int l,int r,int h)
	{
		if(l > r) return 0;

		if(l==r) return (h+l-1)/l;
		if( (b->rs->sum - a->rs->sum) >= h)
			return querysum(a->rs, b->rs, mid+1, r, h);
		else
			return 	querysum(a->ls, b->ls, l, mid, h-(b->rs->sum - a->rs->sum) ) 
							+ b->rs->siz - a->rs->siz ;
	}

	void init2()
	{
		null = newnode();
		null->siz=null->sum=0;
		null->ls=null->rs=null;

		node *now=null;
		root[0]=null;

		for(int i=1;i<=C;i++)
		{
			B[i]=read();
			S[i]=S[i-1]+B[i];
			now = modify(now, 1, 1000, B[i]);
			root[i]=now;
		}

	}

	void work2()
	{
		int x1,x2,y1,y2,h;
		while(M--)
		{
			scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&h);
			if(S[y2]-S[y1-1] < h)  puts("Poor QLW");
			else printf("%d\n" , querysum(root[y1-1], root[y2], 1, 1000, h));
		}
	}

}

int main()
{
	freopen("p2468.txt","r",stdin);
	scanf("%d %d %d ",&R,&C,&M);
	if(R!=1)
	{
		using namespace opt1;
		init1();
		work1();
	}
	else
	{
		using namespace opt2;
		init2();
		work2();
	}
	return 0;
}
