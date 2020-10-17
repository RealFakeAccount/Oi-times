#include <bits/stdc++.h>
using namespace std;
int a[100][1000],n,i,j,now,num[100];


int main()
{
    cin>>n;
    int now=1;
    while (1)
    {
        for (i=1;i<=n;++i)
        {
            if (num[i]==0||(int(sqrt(now+a[i][num[i]])))*(int(sqrt(now+a[i][num[i]])))==now+a[i][num[i]]    )
            {
                ++num[i];
                a[i][num[i]]=now;
                break;
            }
        }
        if (i==n+1)
            break;
        ++now;
    }
    cout<<now-1<<endl;
    for (i=1;i<=n;++i)
    {
        for (j=1;j<=num[i];++j)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }
}
//????
