#include <cstdio>
#include <cstdlib>
#include <cstring>
#define open(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define close fclose(stdin); fclose(stdout); 
using namespace std;

int n,m;
int a[500005],b[500005];

inline int read()
{
    int k=1;
    int sum=0;
    char c=getchar();
    for(;'0'>c || c>'9' ;c=getchar())
        if(c=='-') k=-1;
    for(;'0'<=c && c<='9';c=getchar())
        sum=sum*10+c-'0';
    return sum*k;
}

inline void write(int x)
{
    if(x<0) { putchar('-'); x*=-1; }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}

inline int abs(int x)
{
    return x>0?x:-x;
}

inline int lowbit(int x)
{
    return x&(-x);
}

inline void updata(int x,int y)
{
    for(;x<=n;x+=lowbit(x))
        b[x]+=y;
}

inline int getsum(int x)
{
    int sum=0;
    for(;x;x-=lowbit(x))
        sum+=b[x];
    return sum;
}

int main()
{
   // open("1098");

    int T=read();
    for(;T;--T)
    {
        n=read(); m=read();
        int sum=0;
        for(int i=1;i<=m;++i)
        {
            int f=read();
            if(f)
            {
                int x=abs(getsum(read()-1)-getsum(read()-1));  
                //注意取绝对值(顺序问题);
                //-1不好解释,看图分析(第i条道路连接i与i+1的点);
                //至于read()-1==0的情况,可看样例,不用特殊处理
                write((x&&(sum-x))?0:1);
                putchar('\n');
            }
            else
            {
                int x=read();
                updata(x,a[x]?-1:1);
                //printf("%d %d\n",x,a[x]?-1:1);
                if(a[x]) --sum; else ++sum;
                a[x]^=1;

            }
        }
        putchar('\n');
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
    }

  //  close;
    return 0;
}
