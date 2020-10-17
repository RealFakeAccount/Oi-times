const ll MOD=2019201997; ll n,k,fa[8000],ans=0;

ll cal(ll i,ll j){ return max((1LL*2019201913*i%MOD+1LL*2019201949*j%MOD)%MOD,
    (1LL*2019201913*j%MOD+1LL*2019201949*i%MOD)%MOD); }

ll find_fa(ll x){ return fa[x]=(fa[x]==x)?x:find_fa(fa[x]); }

bool checks(ll mid){
    for(ll i=1;i<=n;i++) fa[i]=i; ll cnt=n;
    for(ll i=1;i<=n;i++) for(ll j=1;j<i;j++){
        ll fx=find_fa(i),fy=find_fa(j);
        if(cal(i,j)<mid&&fx!=fy) fa[fx]=fy,cnt--;
        if(cnt<k)  return false;
    } return true;
}

int main(){
    reads(n),reads(k); ll l=2e7,r=MOD,mid;
    while(l<=r){ mid=(l+r)>>1; if(checks(mid)) ans=mid,l=mid+1; else r=mid-1; }
    cout<<ans<<endl;
}
