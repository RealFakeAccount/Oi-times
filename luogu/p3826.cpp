#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 1e5 + 200;
const int INF = 0x3f3f3f3f;
int N,M,K,lastday = 0,cntvege = 0;

struct vege
{
	int w,num,bad;
	bool sp;
	vege(int w=0,int n=0,int b=0,bool sp=false) : w(w), num(n), bad(b), sp(sp) {}

	bool operator <(const vege &a) const{return w < a.w;}
}v[MAXN],now;

inline void addv(int w,int n,int b,bool sp)
{
	v[++cntvege]=vege(w,n,b,sp);
}

int day[MAXN];
inline int lastd(vege x)
{
	if(x.bad == 0) return lastday;
	if(x.num % x.bad == 0)
		return x.num / x.bad;
	else return x.num / x.bad + 1;
}

inline int soldnum(vege x,int i)
{
	if((x.num / x.bad) < i) return x.num % x.bad;
	return M;
}

namespace ufs
{
	int pre[MAXN];

	void init(int n)
	{
		for(int i = 0; i<=n; i++)
			pre[i] = i;
	}

	inline int findpre(int x)
	{
		if(pre[x] == x)
			return x;
		return pre[x] = findpre(x);
	}

	inline void unite(int add,int nxt)
	{
		pre[findpre(nxt)] = pre[add];//if findpre(add) != add ,assert ERROR!
	}
}

int ask[MAXN];
priority_queue<vege,vector<vege> > q;

vector<pair<vege,int> > sq;
int workans()
{
	int ans = 0;

	
	for(int i=1;i<=cntvege;i++)
		q.push(v[i]);

	int soldout = 0;
	while(!q.empty())
	{
		vege u = q.top();q.pop();
		now = u;
		if(!now.sp)
		{
			now.num--;
			int d = lastd(now);
			for(int i = d; i>0; i--)
			{
				if(day[i] == M) {i = ufs::findpre(i);continue;}
				//if just a single day, "i" still --,doesn`t matter
				if(i == 0) break;
				
				int so = soldnum(now, i);
				if((M - day[i]) > now.num)
				{
					day[i] += now.num;
					now.num = 0;
					break;
				}

				
				ans += now.w * (so);
				now.num -= (so);
				day[i] += so;
				if(day[i] == M) soldout++;
				if(day[i + 1] == M) ufs::unite(i,i+1);
			}
		}

		if(now.sp)
		{
			int d = lastd(u);
			now.num = 1;
			for(int i = d; i>0; i--)
			{
				if(day[i] == M) {i = ufs::findpre(i);continue;}
				
				if(i == 0) break;

				day[i]++,ans += now.w;
				if(day[i] == M) 
					{
						soldout++;
						if(day[i + 1] == M) ufs::unite(i,i+1);
					}
				break;
			}
		}
		
		pair<vege,int> pa = make_pair(u,u.num - now.num);
		sq.push_back(pa);
		if(soldout == lastday)
			break;
		
	}
	return ans;
}

int ans1[MAXN];
void workday(int n)
{
	reverse(sq.begin(),sq.end());
	for(int i = 0; i< (int) sq.size(); i++)
	{
		
	}
	
}
int main()
{
	freopen("p3826.txt","r",stdin);
	cin>>N>>M>>K;

	int a,s,c,x;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d%d%d%d",&a, &s, &c, &x);
		addv(a, c, x, false);
		addv(a + s, c, x, true);
		
	}

	for(int i=1;i<=K;i++)
	{
		scanf("%d",&ask[i]);
		lastday = max(lastday,ask[i]);
	}
	
	
	ufs::init(lastday);
//	cout<<workans()<<endl;
	workday(workans());
	return 0;
}

