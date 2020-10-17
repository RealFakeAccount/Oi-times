#include <bits/stdc++.h>
using namespace std;
const int MAXN = 120;
typedef long long ll;

int N;
ll num[MAXN];
bool vis[MAXN];
int visnum = 0;

vector<ll> cp, ans;
void compress()
{
	for(int i = 1; i <= N; i++)
		cp.push_back(num[i]);
	sort(cp.begin(), cp.end());
	cp.erase(unique(cp.begin(), cp.end()), cp.end());
}

inline int getnum(ll x)
{
	int ans = lower_bound(cp.begin(), cp.end(), x) - cp.begin();
	if(cp[ans] == x) return ans;
	else return -1;
}

bool dfs(ll cur)
{
	int num = getnum(cur);
	if(num == -1) return false;
	if(vis[num]) return false;

	visnum++;vis[num] = true;
	if(visnum == N) 
	{
		ans.push_back(cur);
		return true;
	}

	if(cur % 3 == 0) 
		if(dfs(cur / 3))
		{
			ans.push_back(cur);
			return true;
		}

	if(dfs(cur * 2))
	{
		ans.push_back(cur);
		return true;
	}

	vis[num] = false;
	visnum--;
	return false;
}

int main()
{
	cin>>N;
	for(int i = 1; i <= N; i++)
		cin>>num[i];

	compress();
	for(int i = 1; i <= N; i++)
		if(dfs(num[i]))
		{
			reverse(ans.begin(), ans.end());
			for(int j = 0; j < (int) ans.size(); j++)
				cout<<ans[j]<<" ";
			cout<<endl;
			return 0;
		}

	cout<<-1<<endl;

	return 0;
}