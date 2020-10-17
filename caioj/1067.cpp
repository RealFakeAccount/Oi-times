//https://www.luogu.org/problem/show?pid=1018
#include<iostream>
#include<cstring>
#include<memory.h>
using namespace std;
char dp[41][7][100],tmp[100],a[42];//dp[i][j]表示前i个数插入j个乘号得到的最大数，j可以为0
int n,k;                           //注意是"前i个数"，则第i个数在a中的下标为i-1 
int mul(char s[],int from,int to)  //from和to都是a的下标值。该函数是计算两个数的乘积，转换为字符串的形式
{
    int i,j;
    int s1[100]={0},s2[100]={0},tmp1[100]={0};
    int len1=to-from+1,len2=strlen(s);
    for(i=0;i<len1;i++)
        s1[i]=a[to-i]-'0';
    for(i=0;i<len2;i++)
        s2[i]=s[len2-1-i]-'0';
    for(i=0;i<len1;i++)
        for(j=0;j<len2;j++)
            tmp1[i+j]+=s1[i]*s2[j];
    int k=0;
    for(i=0;i<=len1+len2+2;i++){
        tmp1[i]+=k; 
        if(tmp1[i]>9){
            k=tmp1[i]/10;
            tmp1[i]%=10;
        }
        else k=0;
    }
    for(i=99;tmp1[i]==0&&i!=-1;--i);  //注意这里的i!=-1不能丢，因为相乘可能为0，因为这个调试了一个小时
    for(j=0;j<=i;j++) 
        tmp[j]=tmp1[i-j]+'0';
    tmp[j]=0;
    return i+1;
}
int main()
{
    cin>>n>>k;
    cin>>a;
    int i,j,m;
    for(i=1;i<=n;i++) //对于没有乘号，最大的就是它本身 
        memcpy(dp[i][0],a,i);
    for(j=1;j<=k;j++)
        for(i=j+1;i<=n;i++)
            for(m=j;m<i;m++)
            {
                int lend,lent;
                memset(tmp,0,sizeof tmp);
                lent=mul(dp[m][j-1],m,i-1);
                lend=strlen(dp[i][j]);
                if(lent==lend&&strcmp(tmp,dp[i][j])>0||lent>lend)//切记在strcmp后面加>0！因为这个又调试了一个小时... 
                    strcpy(dp[i][j],tmp);
            }
    //int x,y;while(cin>>x>>y) cout<<dp[x][y]<<endl;
    cout<<dp[n][k];
}