#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+20;
const int INF=0x3f3f3f3f;
struct edge
{
	int dis,num,nxt,pre;
	bool operator < (const edge &c) const {return dis > c.dis;}
}e[MAXN];
priority_queue<edge> q;

bool vis[MAXN];
int N,K;

int main()
{
	memset(vis,false,sizeof(vis));

	cin>>N>>K;

	int last=-INF;
	for(int i=1,y;i<=N;i++)
	{
		scanf("%d",&y);
		e[i].dis=y-last;
		last=y;
		e[i].num=i;

		e[i].pre=i-1;
		e[i].nxt=i+1;

		q.push(e[i]);
	}

	e[N+1].pre=N;
	e[N+1].dis=INF;
	q.push(e[N+1]);

	int ans=0;
	while(K--)
	{
		while(vis[q.top().num]) q.pop();

		int now=q.top().num;q.pop();

		ans+=e[now].dis;
		vis[e[now].pre]=vis[e[now].nxt]=true;
		e[now].dis=e[e[now].pre].dis + e[e[now].nxt].dis - e[now].dis;

		e[now].pre=e[e[now].pre].pre,
		e[now].nxt=e[e[now].nxt].nxt;
		e[e[now].pre].nxt=now,
		e[e[now].nxt].pre=now;

		q.push(e[now]);
	}
	cout<<ans<<endl;
	return 0;
}