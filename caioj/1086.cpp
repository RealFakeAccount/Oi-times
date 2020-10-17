#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int m,n,k;
int w[110],p[110],q[200010];
int f[1010]={0},list[200010];
//����֪ʶ��:����,����,̰�� 

int main()
{
	///freopen("1086.txt","r",stdin);
	cin>>m>>n>>k;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=m;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
		cin>>q[i];
	
	for(int i=1;i<=m;i++)
		for(int j=w[i];j<=k;j++)
			f[j]=max(f[j],f[j-w[i]]+p[i]);
	/*for(int i=1;i<=k;i++)
		{
			cout<<"i="<<i<<endl;
			cout<<f[i]<<endl;
			cout<<"***************"<<endl;
		}
	maxak=f[k];
	cout<<maxak<<endl;*/
	int ss=0,head=1,ans=0;
	for(int i1=1;i1<=n;i1++)
	{
		list[i1]=upper_bound(f+1,f+k,q[i1])-f-1;
		ss+=list[i1];//list[i1]ָ�ӵ�һ�мӵ�i1�е���Դ�� 
		while(ss>k && head<=i1)//̰�� 
		{
			ss-=list[head];
			head++;
		}
		ans=max(ans,i1-head+1);
	}
	cout<<ans<<endl;
	return 0;
}

