#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int max_v=10010;
struct edge
{
	int to,cost;
	edge(int u,int h) : to(u),cost(h) {}
};//边的结构体
typedef pair<int,int> P;//first是最短距离，second是顶点编号，比较时先比first，相同再比second

int V;//点数
vector<edge> G[max_v];//与某点相连的边
int d[max_v];//到起点的最小距离

void dijkstra(int s)
{
	priority_queue<P,vector<P>,greater<P> > que;//greater是默认比较仿函数，声明小顶堆，如果缺省就是大顶堆，队头元素最大。
	memset(d,63,sizeof(d));
	d[s]=0;
	que.push(P(0,s));
	while(!que.empty())
	{
		P p=que.top();
		que.pop();
		int v=p.second;
		if(d[v]<p.first)
			continue;
		for(int i=0;i< (int) G[v].size() ;i++)
		{
			edge e = G[v][i];
			if(d[e.to]> d[v]+e.cost)
			{
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
}

int main()
{
	freopen("1088.txt","r",stdin);
	int N,M,x,y,c;
	cin>>N>>M;
	for(int i=0;i<M;i++)
	{
		scanf("%d%d%d",&x,&y,&c);//x，y，c表示点x到点y之间存在一条边长度为c
		G[x].push_back(edge(y,c));
		G[y].push_back(edge(x,c));
		//cout<<G[x].size()<<endl;
	}
	dijkstra(1);
	cout<<d[N]<<endl;
	return 0;
}
/*const int maxn=10010;
int n,m,x,y,c;
int d[maxn];
bool v[maxn]=false;

struct edge
{
	int to,dist;
	edge(int x,int y):to(x),dist(y){}
};
vector<edge> G[maxn];

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		G[x].push_back( edge( y,c ) );
		G[y].push_back( edge( x,c ) );
	}
	memset(d,63,sizeof(d));
	d[1]=0;v[1]=true;
	queue[1]=1;head=1;tail=2;
	while(head!=tail)
	{
		for ()
	}
	
	queue<int> q;
	q.push(edge(t, 0));
	while (!q.empty()) {
		int u = q.top(); q.pop();
		for (int i = 0; i < (int)G[u].size(); ++i) {
			Edge &e = G[u][i];
			if(d[e.to]>d.[u]+e.dist)
			{
				d[e.to]=d[u]+e.dist;
				if(v[e.to]==false)
				{
					v[e.to]=true;
					q.push(e.to);
				}
			}
			q.push(u);
			v[u]=false;
		}
	
	return 0;
}*/
