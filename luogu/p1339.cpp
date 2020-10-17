#include <bits/stdc++.h>
using namespace std;
const int MAXP= 2500+10;
const int MAXE= 6200+10;

struct edge
{
	int to,cost;
	edge(int u=0,int v=0) : to(u),cost(v) {}
};
typedef pair<int,int> P;//±àºÅ£¬×î¶Ì¾àÀë 
 
int d[MAXP];
vector<edge> g[MAXE];

void dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P> > que;
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
        for(int i=0;i< (int) g[v].size() ;i++)
        {
            edge e = g[v][i];
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
	ios::sync_with_stdio(false);
	int T,C,Ts,Te;
	cin>>T>>C>>Ts>>Te;
	int st,ed,co;
	for(int i=1;i<=C;i++)
	{
		cin>>st>>ed>>co;
		g[st].push_back(edge(ed,co));
		g[ed].push_back(edge(st,co));
	}
	dijkstra(Ts);
	cout<<d[Te]<<endl;
	return 0;
}
