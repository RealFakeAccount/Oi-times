#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
typedef long long ll;

/*【毒瘤开门】
n个毒瘤，都需要出一次门，其中第i个毒瘤会在li时刻离开，并且在第ri时刻回来。
当一个毒瘤离开成都毒瘤中学的时候，门会变成开的。如果这个毒瘤拥有了钥匙，
那么他就可以决定关门或者不关门。同时每一个毒瘤回来的时候要么门本来就是开的，
要么他必须拥有一把钥匙。注意，回来的时候无论有没有钥匙，那么毒瘤都可以把门关上。
只有k把钥匙，只能分给k个毒瘤。希望门开的时间越短越好。*/

int getint(){
    int res=0,fh=1;char ch=getchar();
    while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
    if(ch=='-')fh=-1,ch=getchar();
    while(ch>='0'&&ch<='9')res=res*10+ch-'0',ch=getchar();
    return fh*res;
}

const int maxn=2002;
int l[maxn],r[maxn],pl[maxn],pr[maxn];
int s[maxn],S,f[maxn][maxn][2]; 
//f[i][j][0/1]表示前i个人，用了j个钥匙，最后一个人用/不用钥匙
bool vis[maxn];

struct node{
    int x,num;
    bool operator <(const node b) const{return x<b.x;}
}a[maxn<<1];

void dfs(int x){
    s[++S]=a[x].num;vis[s[S]]=1;
    int last=pr[a[x].num]-1;
    if(a[last].x==l[a[last].num]&&!vis[a[last].num])dfs(last);
}

int main(){
    int n=getint(),k=getint();
    for(int i=1;i<=n;i++){
        l[i]=getint(),r[i]=getint();
        a[i].x=l[i];a[i].num=i;
        a[i+n].x=r[i];a[i+n].num=i;
    }
    sort(a+1,a+n+n+1);
    int kk=0;
    for(int i=1;i<=n<<1;i++){
        if(a[i].x==l[a[i].num]) pl[a[i].num]=i;
        else pr[a[i].num]=i;
        if(i!=1&&a[i].x==l[a[i].num]&&a[i-1].x==r[a[i-1].num])
            kk+=a[i].x-a[i-1].x;
    }
    for(int i=1;i<=n<<1;i++)
        if(!vis[a[i].num]) dfs(i);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            f[i][j][0]=max(f[i-1][j][1],f[i-1][j][0]);
            if(j!=0){
                if(pl[s[i]]+1==pr[s[i]]){
                    f[i][j][1]=max(f[i-1][j-1][0],f[i-1][j-1][1])+
                        a[pr[s[i]]].x-a[pl[s[i]]].x;
                    continue;
                }
                int last=a[pl[s[i]]+1].num,rl=a[pr[s[i]]-1].num,zuo=0,you=0;
                if(pl[rl]!=pr[s[i]]-1) you=a[pr[s[i]]].x-a[pr[s[i]]-1].x;
                if(pr[last]!=pl[s[i]]+1) zuo=a[pl[s[i]]+1].x-a[pl[s[i]]].x;
                else if(j>=2) f[i][j][1]=f[i-1][j-1][1]+you+
                                 a[pl[s[i]]+1].x-a[pl[s[i]]].x;
                f[i][j][1]=max(f[i][j][1],
                                max(f[i-1][j-1][0],f[i-1][j-1][1])+zuo+you);
            }
        }
    }
    printf("%d",a[n+n].x-a[1].x-max(f[n][k][0],f[n][k][1])-kk);
    return 0;
}

④                     ================
③/⑤       -------                              ------
②      -------------------------
①   ========================= 
    1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17
状态 X  O  O  O  X  X  X  X  O  X  X  X  X  X  O  O 