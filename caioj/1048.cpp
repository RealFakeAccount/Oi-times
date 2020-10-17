#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

struct node
{
	int a,b,c；
	int s=0;
}q[1000];
int head,tail;
int book[100][100][100];
int ma,mb,mc,k;
bool flag=true;
int main()
{
	memset(book,0,sizeof(book));
	head=0;tail=1;
	cin>>ma>>mb>>mc>>k;
	do
	{
		head++;
		if(q[head].a>0)//a倒油
		{
			if(q[head].b<mb)//b接油
			{
				if(q[head].a>=(mb-q[head].b))//b的空间多还是a的油多？
				{
					for( int i=1;i<=tail;i++)//判重
					{
						if( (q[i].a==q[head].a-(mb-q[head].b)) && (q[i].b==mb) && (q[i].c==q[head].c) )
						{
							flag=false;
							break;
						}
					}
					if(flag)
					{
						q[tail].a=q[head].a-(mb-q[head].b);
						q[tail].b=mb;
						q[tail].c=q[head].c;
						q[tail].s=q[head].s+1
						tail++;
					}
				}
				if(q[head].a<(mb-q[head].b))
				{
					for( int i=1;i<=tail;i++)//判重
					{
						if( (q[i].a==0) && (q[i].b==q[head].b+q[head].a) && (q[i].c==q[head].c) )
						{
							flag=false;
							break;
						}
					}
					if(flag)
					{
						q[head].b=q[head].b+q[head].a;
						q[head].a=0;
						tail++;
					}
				}
			}
			if(q[head].c<mc)//c接油
			{
				if(q[head].a>=(mc-q[head].c))//c的空间多还是a的油多？
				{
					for( int i=1;i<=tail;i++)//判重
					{
						if( (q[i].a==q[head].a-(mc-q[head].c)) && (q[i].b==q[head].b) && (q[i].c==mc) )
						{
							flag=false;
							break;
						}
					}
					if(flag)
					{
						q[head].a=q[head].a-(mc-q[head].c);
						q[head].c=mc;
						tail++;
					}
				}
				if(q[head].a<(mc-q[head].c))
				{
					for( int i=1;i<=tail;i++)//判重
					{
						if( (q[i].a==0) && (q[i].b==q[head].b) && (q[i].c==q[head].c+q[head].a) )
						{
							flag=false;
							break;
						}
					}
					if(flag)
					{
						q[head].c=q[head].c+q[head].a;
						q[head].a=0;
						tail++;
					}
				}
			}
		}
		if(q[head].b>0)//b倒油
		{
			if(q[head].a<ma)//a接油
			{
				if(q[head].b>=(ma-q[head].a))//a的空间多还是b的油多？
				{
					for( int i=1;i<=tail;i++)//判重
					{
						if( (q[i].a==ma) && (q[i].b==q[head].b-(mb-q[head].b)) && (q[i].c==q[head].c) )
						{
							flag=false;
							break;
						}
					}
					if(flag)
					{
						q[head].b=q[head].b-(mb-q[head].b);
						q[head].a=ma;
						tail++;
					}
				}
				if(q[head].b<(ma-q[head].a))
				{
					for( int i=1;i<=tail;i++)//判重
					{
						if( (q[i].a==ma) && (q[i].b==q[head].b-(mb-q[head].b)) && (q[i].c==q[head].c) )
						{
							flag=false;
							break;
						}
					}
					if(flag)
					{
						q[head].b=q[head].b-(mb-q[head].b);
						q[head].a=ma;
						tail++;
					}
				}
			}
			if(q[head].c<mc)//c接油
			{
				if(q[head].b>=(mc-q[head].c))//c的空间多还是b的油多？
				{
					for( int i=1;i<=tail;i++)//判重
					{
						if( (q[i].a==q[head].a) && (q[i].b==q[head].b-(mc-q[head].c)) && (q[i].c==mc) )
						{
							flag=false;
							break;
						}
					}
					if(flag)
					{
						q[head].b=q[head].b-(mc-q[head].c);
						q[head].c=mc;
						tail++;
					}
				}
				if(q[head].b<(mc-q[head].c))
				{
					for( int i=1;i<=tail;i++)//判重
					{
						if( (q[i].a==q[head].a) && (q[i].b==0) && (q[i].c==q[head].c+q[head].b) )
						{
							flag=false;
							break;
						}
					}
					if(flag)
					{
						q[head].c=q[head].c+q[head].b;
						q[head].b=0;
						tail++;
					}
				}
			}
		}
		if(q[head].c>0)//c倒油
		{
			if(q[head].b<mb)//b接油
			{
				if(q[head].c>=(mb-q[head].b))//b的空间多还是c的油多？
				{
					for( int i=1;i<=tail;i++)//判重
					{
						if( (q[i].a==q[head].a) && (q[i].b==mb) && (q[i].c==q[head].c-(mb-q[head].b)) )
						{
							flag=false;
							break;
						}
					}
					if(flag)
					{
						q[head].c=q[head].c-(mb-q[head].b);
						q[head].b=mb;
						tail++;
					}
				}
				if(q[head].c<(mb-q[head].b))
				{
					for( int i=1;i<=tail;i++)//判重
					{
						if( (q[i].a==q[head].a) && (q[i].b==q[head].b+q[head].c) && (q[i].c==0) )
						{
							flag=false;
							break;
						}
					}
					if(flag)
					{
						q[head].b=q[head].b+q[head].c;
						q[head].c=0;
						tail++;
					}
				}
			}
			if(q[head].c<mc)//a接油
			{
				if(q[head].c>=(ma-q[head].a))//a的空间多还是c的油多？
				{
					for( int i=1;i<=tail;i++)//判重
					{
						if( (q[i].a==ma) && (q[i].b==q[head].b) && (q[i].c==q[head].c-(ma-q[head].a)) )
						{
							flag=false;
							break;
						}
					}
					if(flag)
					{
						q[head].c=q[head].c-(ma-q[head].a);
						q[head].a=ma;
						tail++;
					}
				}
				if(q[head].c<(ma-q[head].a))
				{
					for( int i=1;i<=tail;i++)//判重
					{
						if( (q[i].a==q[head].a+q[head].c) && (q[i].b==q[head].b) && (q[i].c==0) )
						{
							flag=false;
							break;
						}
					}
					if(flag)
					{
						q[head].a=q[head].a+q[head].c;
						q[head].c=0;
						tail++;
					}
				}
			}
		}
	}while(head<tail);
}