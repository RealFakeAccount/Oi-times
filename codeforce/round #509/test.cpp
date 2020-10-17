#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
using namespace std;
typedef unsigned long long ll;

/*【D】*/

ll sum1[200019],sum2[200019];

int main(){
	ll n,h,le,ri,lastt=0; cin>>n>>h;
	for(ll i=1;i<=n;i++){
		cin>>le>>ri; sum1[i]=sum1[i-1]+ri-le;
		sum2[i]=sum2[i-1]+le-lastt; lastt=ri;
	} ll l=0,r=1,ans=h;
	while(l<=n&&r<=n){
		while(sum2[r]-sum2[l]<h&&r<=n){
			ans=max(ans,h+sum1[r]-max((ll)0,sum1[l-1])); r++;
		} l++;
	} cout<<ans<<endl;
}