#include<queue>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#define N 7000
using namespace std;
inline void read(int &x)
{
    x=0;
    int p=1;
    char c=getchar();
    while(!isdigit(c)){if(c=='-')p=-1;c=getchar();}
    while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^'0');c=getchar();}
    x*=p;
}
int n;
int to[N],beg[N],nex[N],match[N];
int vis[N];
int e;
int ans;
void add(int x,int y)
{
    to[++e]=y;
    nex[e]=beg[x];
    beg[x]=e;
}
int dfs(int x)
{
    for(int i=beg[x];i;i=nex[i])
    {
        int y=to[i];
        if(!vis[y])
        {
            vis[y]=1;
            if(!match[y]||dfs(match[y]))
            {
                match[y]=x;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(beg,0,sizeof(beg));
        e=0;
        for(int i=1;i<=n;i++)
        {
            int x,gs;
            read(x);
            read(gs);
            x++;
            int y;
            for(int j=1;j<=gs;j++)read(y),y++,add(x,y),add(y,x);
        }
        ans=0;
        memset(match,0,sizeof(match));
        for(int i=1;i<=n;i++)
        {
        memset(vis,0,sizeof(vis));
        if(dfs(i))ans++;
        }
        printf("%d\n",ans/2);
    }
    return 0;
}
