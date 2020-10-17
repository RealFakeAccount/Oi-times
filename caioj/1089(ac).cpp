#include <algorithm>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxm=100+10;
 
struct edge
{
    int to,cost;
    edge(int u,int v) : to(u),cost(v) {}
};
typedef pair<int,int> P;
 
int d[maxm];	
vector<edge> G[maxm];
 
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
	int N,M;
    //freopen("1089.txt","r",stdin);
   while(scanf("%d%d",&N,&M)==2)

   {	
		bool destroy[maxm][maxm];
   		 int x,y,c;
   		 for(int i=0;i<M;i++)
   		 {
   		     scanf("%d%d%d",&x,&y,&c);
   		     G[x].push_back(edge(y,c));
   		     G[y].push_back(edge(x,c));
   		 }
     
    	int D,I,J;
   		 cin>>D;
   		 memset(destroy,false,sizeof(destroy));
   		 for(int i=0;i<D;i++)
   		 {
    	    scanf("%d%d",&I,&J);
    	   	destroy[I][J]=true;
    	   	destroy[J][I]=true;
   		 }
     
    	for(int i=1;i<=N;i++)
    	    for(int j=0;j< (int) G[i].size() ;j++)
   	         if(destroy[i][G[i][j].to]==false)
   	             G[i][j].cost=0; 
     
  	  int A,B;
  	  cin>>A>>B;
 	   dijkstra(A);
     
  	  cout<<d[B]<<endl;
  	for(int i=1;i<=N;i++) G[i].clear();
	}	
    return 0;
}

