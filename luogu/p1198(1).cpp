#include <bits/stdc++.h>
#define MAXN 200000
#define LL long long
#define INF 20000010
using namespace std;
int last,m,d,t;
int tree[MAXN*4];
int query(int now,int l,int r,int check_l,int check_r)
{
    if ((l>=check_l)&&(r<=check_r)) return tree[now];
    int ans=-1*INF,mid;
    mid=(l+r)>>1;
    if (mid>=check_l) ans=max(ans,query(now<<1,l,mid,check_l,check_r));
    if (mid<check_r) ans=max(ans,query(now<<1|1,mid+1,r,check_l,check_r));
    return ans;//·µ»Øans
}
void pushup(int now,int l,int r,int position,int num)
{
    if ((l==position)&&(r==position))
    {
        tree[now]=num;
        return;
    }
    int mid;
    mid=(l+r)>>1;
    if (position<=mid) pushup(now<<1,l,mid,position,num);
    if (position>mid) pushup(now<<1|1,mid+1,r,position,num);
    tree[now]=max(tree[now<<1],tree[now<<1|1]);
}
int main()
{
    char c;
    int i,j;
    LL n;
    scanf("%d%d",&m,&d);
    for (i=1;i<=m;i++) tree[i]=-1*INF;
    for (i=1;i<=m;i++)
    {
        cin>>c;
        scanf("%lld",&n);
        if (c=='Q')
        { 
            int ans;
            ans=query(1,1,m,last-n+1,last);
            printf("%d\n",ans);
            t=ans;
        }
        if (c=='A')
        {
            last++;
            int num;
            num=(n+t)%d;
            pushup(1,1,m,last,num);
        }
    }
    return 0;
} 
