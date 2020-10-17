#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 20000 + 7;
const int MAXM = 100000 + 7;
int n, m;
int k;
int L = 0;
int R = 0;
int color[MAXM];
vector<int> g[MAXM];
struct node
{
    int from, to, dist;
    node(int a = 0, int b = 0, int c = 0): from(a), to(b), dist(c){}
};
vector<node> edges;

void input()
{
    scanf("%d %d\n",&n, &m);
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d\n",&u, &v, &w);
        u --;
        v --;
        R = max(R, w);
        g[u].push_back(edges.size());
        edges.push_back(node(u, v, w));
        g[v].push_back(edges.size());
        edges.push_back(node(v, u, w));
    }
}

bool dfs(int v)
{
    for(int i = 0; i < g[v].size(); i ++)
    {
        node& a = edges[g[v][i]];//��a����ʾedges[g[v][i]]�ĵ�ַ��ֻҪ��edges���õĽṹ���е�Ԫ�أ�a����ʹ��
        if(a.dist <= k)
            continue;
        if(color[a.to] == color[v])
            return false;
        if(!color[a.to])
        {
            color[a.to] = 3 - color[v];//
            if(!dfs(a.to))
                return false;
        }
    }
    return true;
}

bool C(int x)
{
    k = x;
    for(int i = 0; i < n; i++)
        color[i] =0;//color��ʼ��Ϊfalse
    for(int i = 0; i < n; i++)
    {
        if(!color[i])//colorû�з��ʹ�
        {
            color[i] = 1;
            if(!dfs(i))//�������Ⱦɫ
                return false;
        }
    }
    return true;
}

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    #endif
    
    input();
    
    while(R > L)//[R, L]���Ҿ�Ϊ������
    {
        int mid = (L + R) / 2;//
        if(C(mid))
            R = mid;
        else
            L = mid + 1;
    }
    printf("%d\n",L);
    return 0;
}    
