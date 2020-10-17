#include <bits/stdc++.h>
using namespace std;
const int MAXN=100+5;

struct edge
{
    int to,cap,rev;
    edge(int to,int cap,int rev) : to(to),cap(cap),rev(rev) {
    }
};
//--------dinic
int s,t;
int iter[MAXN*4],level[MAXN*4];
vector<edge> g[MAXN*4];

inline void addedge(int u,int v,int c)
{
    g[u].push_back(edge(v,c,g[v].size()));
    g[v].push_back(edge(u,0,g[u].size()-1));
}

bool bfs()
{
    memset(level,-1,sizeof(level));
    queue<int> q;
    
    level[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=0;i<(int)g[u].size();i++ )
        {
            edge &e=g[u][i];
            if(e.cap && level[e.to]==-1)
            {
                level[e.to]=level[u]+1;
                q.push(e.to);
            }
        }
    }
    return ~level[t];
}

int dfs(int u,int flow)
{
    if(u==t)
        return flow;
        
    for(int &i=iter[u];i<(int)g[u].size();i++)
    {
        edge &e=g[u][i];
        if(e.cap && level[e.to]==level[u]+1)
        {
            int d=dfs(e.to,min(flow,e.cap));
            if(d)
            {
                e.cap-=d;
                g[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}

long long maxflow()
{
    long long flow=0,d=0;
    
    while(bfs())
    {
        memset(iter,0,sizeof(iter));
        
        while(d=dfs(s,INT_MAX),d)
            flow+=d;
    }
    return flow;
}
//--------end
int main()
{
//	freopen("p1042.txt","r",stdin);
    ios::sync_with_stdio(false);
    int n,p,q,ca;
    cin>>n>>p>>q;
    
    s=0,t=2*n+p+q+1;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=2*n+1;j<=2*n+p;j++)
        {
            cin>>ca;
            if(ca)
                addedge(j,i,1);
        }
    }
    for(int i=n+1;i<=2*n;i++)
    {
        for(int j=2*n+p+1;j<=2*n+p+q;j++)
        {
            cin>>ca;
            if(ca)
                addedge(i,j,1);
        }
    }
    
    
    for(int i=2*n+1;i<=2*n+p;i++)
        addedge(s,i,1);
    for(int j=2*n+p+1;j<=2*n+p+q;j++)
        addedge(j,t,1);
            
    for(int i=1;i<=n;i++)
        for(int j=n+1;j<=2*n;j++)
            addedge(i,j,1);
    
    cout<<maxflow()<<endl;
    return 0;
}
