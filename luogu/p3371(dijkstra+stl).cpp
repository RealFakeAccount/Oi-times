#include <bits/stdc++.h>
using namespace std;
const int MAXN=10000+10;
typedef pair<int,int> P;//dis,num
struct edge
{
    int to,cost;
    edge(int u=0,int v=0) : to(u),cost(v) {
    }
};
vector<edge>g[MAXN];
int d[MAXN];int N,M,S;
void dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P> >que;
    fill(d+1,d+N+1,2147483647);
    //cout<<d[1]<<endl;
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty())
    {
        P p=que.top();que.pop();
        int v=p.second;
        if(d[v]<p.first)
            continue;
 		for(int i=0;i<(int) g[v].size();i++)
 		{
 			edge e=g[v][i];
 			if(d[v]+e.cost<d[e.to])
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
    cin>>N>>M>>S;
    int x,y,z;
    for(int i=1;i<=M;i++)
    {
        cin>>x>>y>>z;
        g[x].push_back(edge(y,z));
    //	g[y].push_back(edge(x,z));
    }
    dijkstra(S);
    for(int i=1;i<=N;i++)
        cout<<d[i]<<" ";
    return 0;
}
