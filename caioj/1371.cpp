#include <bits/stdc++.h>
using namespace std;
const int MAXN=100000+2;
 
int f[MAXN];
 
int main()
{
    ios::sync_with_stdio(false);
    int N,M,x,y,z;
    cin>>N;
     
    for(int i=0;i<N;i++)
        cin>>f[i];
     
    cin>>M;
    while(M--)
    {
        cin>>x;
        y=lower_bound(f,f+N,x)-f;
        z=upper_bound(f,f+N,x)-f;
         
        if(f[y]==x)
        {
            cout<<x<<endl;
            continue;
        }
         
        if(f[0]>x)
        {
            cout<<f[0]<<endl;
            continue;
        }
         
        if(f[N-1]<x)
        {
            cout<<f[N-1]<<endl;
            continue;
        }
         
        if ( abs(x-f[y-1]) > abs(x-f[z]) )
            cout<<f[z]<<endl;
        else
            cout<<f[y-1]<<endl;
    }
}

