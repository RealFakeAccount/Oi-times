#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 1e3 + 20;
const int MOD = 19260817;

int N;
int a[MAXN];

namespace _Hash
{
	
	struct Hash
	{
	    int x;
	    int apos,bpos;
	    Hash *next;
	};//挂链法防止冲突 

	Hash hash[1123456],*first[21234567];

	int hashval(int x)
	{
	    return ((x << 1) + (x >> 1)) & 16777215;
	}//hash函数 

	int hashmapnum(0);

	void insert(int x,int pos1,int pos2)
	{
	    int ithash = hashval(x);
	    ++hashmapnum;
	    Hash &addhash = hash[hashmapnum];
	    addhash.x = x;
	    addhash.apos = pos1;
	    addhash.bpos = pos2;
	    addhash.next = first[ithash];
	    first[ithash] = &addhash;
	}//链表插入hash 

	void init()
	{
	    hashmapnum = 0;
	    memset(first,0,sizeof(first));
	}//清空指针 
}

int main()
{
	using namespace _Hash;
	while(cin>>N, N)
	{
		init();
		for(int i = 1; i <= N; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + N + 1);
		for(int i = 1; i < N; i++)
			for(int j = i + 1; j <= N; j++)
				insert(i, j, a[i] + a[j]);
		bool flag = false;
		for(int d = N; d >= 1; d--)
		{
			for(int c = 1; c <= N; c++)
			{
				if(c != d)
				{	
	                int val = a[d] - a[c];
	                int ithash = hashval(val);
	                for(Hash *itr(first[ithash]);itr;itr = itr->next)
	                {
	                    if(itr->x == val)
	                    {
	                        int pos1 = itr->apos,pos2 = itr->bpos;
	                        if(pos1 != c && pos1 != d && pos2 != c && pos2 != d)
	                        {
	                            flag = true;
	                            printf("%d\n",a[d]);
	                        }
	                        break;
						}
					}
				}if(flag) break;
			}if(flag) break;
		}
		if(!flag) puts("no solution");
	}
	return 0;
}
