#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxm=200000+10;
const int maxn=10000+10;
const int maxx=999999999;
const int INF = 0x3f3f3f3f;
typedef pair<int,int> P;//first为距离，second为端点

vector<int> g[maxn << 1];
vector<int> f[maxn << 1];
int m,n;
int ansstart,ansend;
int d[maxn];
bool update[maxn];
int ans;

void dijkstra(int s)
{
	priority_queue<P,vector<P>,greater<P> > que;
	memset(d,INF,sizeof(d));

	d[s]=0;
	que.push(P(0,s));
	while(!que.empty())
	{
		P p=que.top();que.pop();
		int t=p.second;
		if(p.first>d[t])
			continue;
		for(int i=0;i< (int) g[t].size() ;i++)
			if( d[ g[t][i] ] > d[t]+1 && update[g[t][i]]==true)
			{
				d[ g[t][i] ]=d[t]+1;
				que.push(P(d[ g[t][i] ],g[t][i] ));
				//cout<<d[ g[t][i] ]<<" "<<g[t][i]<<endl;
			}
	}
	if(d[ansend]==INF) ans = -1;
	else ans = d[ansend];
}
/*
void dfs(int e)
{
	update[e]=true;
	if(e==ansstart)
		return;
	else
		for(int i=0;i< (int) f[e].size() ;i++)
			if(update[f[e][i]]==false)
				dfs(f[e][i]); 
}
*/

inline void dfs(int u) {
//	printf("%d\n", u);
	update[u] = 1;
	for (int i = 0; i < (int)f[u].size(); ++i) if (!update[f[u][i]]) dfs(f[u][i]);
}

int update1[maxn];
inline void solve() {
	memset(update1, 0, sizeof update1);
	for (int i = 1; i <= n; ++i) if (!update[i]) {
		for (int j = 0; j < (int)f[i].size(); ++j) {
			update1[f[i][j]] = 1;
		}
	}
	for (int i = 1; i <= n; ++i) if (update1[i]) update[i] = 0;
//	for (int i = 1; i <= n; ++i) if (!update[i]) printf("%d\n", i);
}
/*
void solve()
{
	for(int i=1;i<=n;i++)
		if(update[i]==false)
			for(int j=0;j< (int) f[i].size() ;j++)
			{
				update[f[i][j]]=false;
				//cout<<j<<endl;
			}
}
*/
int main()
{
	//freopen("p2296.txt","r",stdin);
	//freopen("road .in","r",stdin);
	//freopen("road .out","w",stdout);
	cin>>n>>m;
	int x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		f[y].push_back(x); // reverse
	}
	cin>>ansstart>>ansend;
	memset(update,false,sizeof(update));	
	dfs(ansend);
	solve(); //

	ans = 0;
	if (update[ansstart] == 0) ans = -1;
	else dijkstra(ansstart);
	
	printf("%d\n", ans);

	return 0;
}
