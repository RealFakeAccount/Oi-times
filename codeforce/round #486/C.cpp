#include<bits/stdc++.h>
#define MAXN 200000 + 10
#define MAXM 10000 + 10
using namespace std;
typedef long long LL;
LL K;
LL N , sum = 0 , a[MAXN];

map<LL , pair<LL , LL> > m;
map<LL , bool> M;

int main()
{
    cin >> K;
    for(int r = 1;r <= K;r++)
    {
        cin >> N;
        sum = 0;
        for(LL i = 1;i <= N;i++) cin >> a[i] , sum += a[i];

        for(LL i = 1;i <= N;i++)
        {
            if(M[sum - a[i]])
            {
            	puts("YES");
                pair<LL , LL> pr = m[sum - a[i]];
                cout << pr . first << " " << pr . second;
                cout << endl;
                cout << r << " " << i << endl;
                return 0;
            }
        }
        for(int i = 1;i <= N;i++){
            M[sum - a[i]] = true;
            pair<LL , LL> pr;
            pr . first = r;
            pr . second = i;
            m[sum - a[i]] = pr;
        }
    }
    puts("NO");
    return 0;
}