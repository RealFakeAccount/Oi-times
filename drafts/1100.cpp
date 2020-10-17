#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<bitset>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1000005;
struct qq
{
    int l,r;
    int s1,s2;
    bitset<51> c;
    int lazy;
}s[N*2];int num=0;
int l,m;
void bt (int l,int r)
{
    int a=++num;
    s[a].l=l;s[a].r=r;
    s[a].lazy=0;
    s[a].c.reset();
    s[a].c[1]=1;
    if (l==r)   return ;
    int mid=(l+r)>>1;
    s[a].s1=num+1;bt(l,mid);
    s[a].s2=num+1;bt(mid+1,r);
}
void update (int x)
{
    int s1=s[x].s1,s2=s[x].s2;
    int lazy=s[x].lazy;s[x].lazy=0;
    s[s1].c.reset();s[s1].c[lazy]=1;s[s1].lazy=lazy;
    s[s2].c.reset();s[s2].c[lazy]=1;s[s2].lazy=lazy;
    return ;
}
void change (int now,int l,int r,int tt)//这一段范围都变成这个 
{
    if (s[now].l==l&&s[now].r==r)
    {
        s[now].c.reset();
        s[now].c[tt]=1;
        s[now].lazy=tt;
        return ;
    }
    if (s[now].lazy!=0) update(now);
    int s1=s[now].s1,s2=s[now].s2;
    int mid=(s[now].l+s[now].r)>>1;
    if (r<=mid) change(s1,l,r,tt);
    else if (l>mid) change(s2,l,r,tt);
    else change(s1,l,mid,tt),change(s2,mid+1,r,tt);
    s[now].c=(s[s[now].s1].c|s[s[now].s2].c);

    return ;
}
bitset<51> ans;
void solve (int now,int l,int r)
{
    if (s[now].l==l&&s[now].r==r)
    {
        ans=(ans|s[now].c);
        return ;
    }
    if (s[now].lazy!=0)update(now);
    int s1=s[now].s1,s2=s[now].s2;
    int mid=(s[now].l+s[now].r)>>1;
    if (r<=mid) solve(s1,l,r);
    else if (l>mid) solve(s2,l,r);
    else solve(s1,l,mid),solve(s2,mid+1,r);
}
int main()
{
    scanf("%d%d",&l,&m);
    bt(1,l);
    for (int u=1;u<=m;u++)
    {
        char ss[5];
        scanf("%s",ss);
        if (ss[0]=='C')
        {
            int l,r,tt;
            scanf("%d%d%d",&l,&r,&tt);
            if (l>r) swap(l,r);
            change(1,l,r,tt);
        }
        else
        {
            ans.reset();
            int l,r;
            scanf("%d%d",&l,&r);
            if (l>r) swap(l,r);
            solve(1,l,r);
            printf("%d\n",ans.count());
        }
    }
    return 0;
}
