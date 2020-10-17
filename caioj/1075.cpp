#include<iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>//STL 通用算法
using namespace std;
int n,e[300],s[300][300],maxn=-1;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){cin>>e[i];e[i+n]=e[i];}
    //珠子由环拆分为链，重复存储一遍
    for(int i=2;i<2*n;i++){
        for(int j=i-1;i-j<n&&j>=1;j--){//从i开始向前推
            for(int k=j;k<i;k++)//k是项链的左右区间的划分点 
            s[j][i]=max(s[j][i],s[j][k]+s[k+1][i]+e[j]*e[k+1]*e[i+1]);
            //状态转移方程：max(原来能量，左区间能量+右区间能量+合并后生成能量）  
            if(s[j][i]>maxn)maxn=s[j][i];//求最大值 
        }
    } 
    cout<<maxn<<endl;
    return 0;
}
