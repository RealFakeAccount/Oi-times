    #include<iostream>  
    #include<cstdio>  
    #include<algorithm>  
    #include<cstring>  
    #include<cmath>  
    #define N 1000003  
    #define ll long long   
    using namespace std;  
    int n,m,s,tot;  
    int point[N],mynext[N],v[N];  
    ll c[N],dis[N],maxn,son[N],len,delta[N];  
    ll ans[N];  
    void add(int x,int y,ll z)  
    {  
        tot++; mynext[tot]=point[x]; point[x]=tot; v[tot]=y; c[tot]=z;  
        tot++; mynext[tot]=point[y]; point[y]=tot; v[tot]=x; c[tot]=z;  
    }  
    void dfs(int x,int fa)  
    {  
        bool f=false;  
        for (int i=point[x];i;i=mynext[i])  
         if (v[i]!=fa)  
         {  
            f=true;  
            dis[v[i]]=dis[x]+c[i];  
            dfs(v[i],x);  
            maxn=max(maxn,dis[v[i]]);  
            son[x]=max(son[x],son[v[i]]);  
         }  
        if (!f)  son[x]=dis[x];   
    }  
    void dfs1(int x,int fa)  
    {  
        ll t=maxn-son[x]-delta[x];  
        ans[x]=t;  
        for (int i=point[x];i;i=mynext[i])  
         if (v[i]!=fa)  
         {  
            delta[v[i]]=delta[x]+t;  
            dfs1(v[i],x);  
         }  
    }  
    int main()  
    {  
        scanf("%d%d",&n,&s);  
        for (int i=1;i<n;i++)  
         {  
            int x,y;  
            ll z;  
            scanf("%d%d%lld",&x,&y,&z);  
            add(x,y,z);  
         }  
        dis[s]=0;  
        dfs(s,0);   
        dfs1(s,0);  
        ll sum=0;  
        for (int i=1;i<=n;i++)  
         sum+=ans[i];  
        printf("%lld",sum);  
    }  
