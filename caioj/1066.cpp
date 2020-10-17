#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1005;

struct car
{
    int w;
    double t;
};

int wm,l,n;
car z[N];
double f[N];

int main()
{
    scanf("%d%d%d\n",&wm,&l,&n);
    for(int a=1;a<=n;++a)
    {
        scanf("%d%lf",&z[a].w,&z[a].t);
        z[a].t=(double)l/z[a].t;
    }
    memset(f,127,sizeof(f));
    f[0]=0.0;
    double mt=0;
    long long mm=0;
    for(int a=1;a<=n;++a)    //前a车 
    {
        mt=0; mm=0;
        for(int c=a;c>=1;--c)    //最后一组的第一辆车是c 
        {
            mm+=z[c].w;
            if(mm>wm) break;
            mt=max(mt,z[c].t);
            f[a]=min(f[a],f[c-1]+mt);
        }
    }
    printf("%.1lf\n",f[n]*60);
	return 0;
}
