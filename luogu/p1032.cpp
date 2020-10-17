#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int MAXN = 22;

string A, B, rulef[7], rulet[7];
int num = 1;

struct P
{
	string x;
	int cnt;
};

queue<P> q;
set<string> M;
int bfs()
{
	P s;
	s.x = A;
	s.cnt = 0;

	M.insert(A);
	q.push(s);
	while(!q.empty())
	{
		P cur = q.front(); q.pop();
		if(cur.x == B) return cur.cnt;
		if(cur.cnt > 10) continue;

		for(int i = 1; i <= num; i++)
		{
			int len = rulef[i].length();
			for(int j = 0; j <= (int) cur.x.length() - len; j++)
			{
				if(cur.x.compare(j, len, rulef[i], 0, len) == 0)
				{
					P nxt;
					nxt = cur;
					nxt.x.replace(j, len, rulet[i]);
					if(M.find(nxt.x) == M.end())
					{
						M.insert(nxt.x);
						//cout<<nxt.x<<endl;
						nxt.cnt++;
						q.push(nxt);
					}
					
				}
			}
		}
	}
	return -1;
}

int main()
{
	//freopen("p1032.txt", "r", stdin);
	cin>>A>>B;
	//cout<<A<<" "<<B<<endl;
	while(cin>>rulef[num]>>rulet[num]) 
		//cout<<rulef[num]<<" "<<rulet[num]<<" "<<num<<endl;
		num++;
	num--;
	//cout<<num<<endl;
	//for(int i = 1; i <= num; i++)
	//	cout<<rulef[i]<<" "<<rulet[i]<<endl;

	int ans = bfs();
	if(ans == -1) cout<<"NO ANSWER!"<<endl;
	else cout<<ans<<endl;
	return 0;
}
