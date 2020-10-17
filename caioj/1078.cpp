#include<iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>
using namespace std;
struct node
{
	int head;
	int tail;
	node()
	{
		head=0;tail=0;
	}
}l[1001];

int cmp(node x,node y)  
{  
    if(x.head==y.head) return x.tail<y.tail;  
    return x.head<y.head;  
}  

int f[1001]={0};

int main()
{
	freopen("1078.txt","r",stdin);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>l[i].head>>l[i].tail;
	sort(l+1,l+n+1,cmp); 
	for(int i=1;i<=n;i++)
		cout<<l[i].head<<" "<<l[i].tail<<endl;
	//cout<<endl;
	for (int i=1;i<=n;i++)  
        f[i]=l[i].head-l[i].tail+1; 
	for (int i=1;i<=n;i++)  
        for (int j=1;j<=i-1;j++)  
            if (l[j].tail<l[i].head)
				f[i]=max(f[i],f[j]+l[i].head-l[i].tail+1);  
	int max1=0;  
    for (int i=1;i<=n;i++)  
	{
		//cout<<f[i]<<endl;
        max1=max(max1,f[i]);  }
    cout<<max1<<endl; 
	return 0;
}
