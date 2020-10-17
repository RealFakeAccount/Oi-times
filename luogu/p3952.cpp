#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;
typedef pair<char, int> P;


int T, L;
bool mode; 
int _times, times, loop, ans, flag;

void init()
{
	times = _times = loop = ans = 0;
	flag = 0;
}

void rest(int cur, bool type)
{
	char buf[50];
	scanf("%*[^\n]\n");
	for(int i = cur; i <= L; i++)
		fgets(buf, sizeof(buf), stdin);
		//scanf(" %[^\n]\n", buf);
	cout<<"ERR"<<endl;
}

inline int dig(char ch[])
{
	int x = 0;
	for(int i = 0; i < (int) strlen(ch); i++)
		x = x * 10 + ch[i] - '0';
	return x;
}

bool solve()
{
	cin>>L;
	char ch; map<char, bool> M; stack<P> sta;

	scanf(" O("), ch = getchar();
	if(ch == '1') mode = false, scanf(")");
	else scanf("^%d)", &_times), mode = true;

	for(int p = 1; p <= L; p++)
	{
		scanf(" %c", &ch);
		if(ch == 'F')
		{
			scanf(" %c", &ch);
			if(M.find(ch) != M.end() && M[ch] == true) 
				return rest(p, 1), false;

			M[ch] = true; loop++;
			char l[5], r[5];
			scanf(" %[0-9n] %[0-9n]", l, r);
			if(isdigit(l[0]) && r[0] == 'n')
			{
				if(!flag) sta.push(P(ch, 1)), times++;
				else sta.push(P(ch, 3)); 
			}//有效循环
			else if((l[0] == 'n' && isdigit(r[0])) || (isdigit(l[0]) && isdigit(r[0])
			 && dig(l) > dig(r)))
				sta.push(P(ch, 2)), flag++;//非法循环
			else sta.push(P(ch, 0));//无效循环
			ans = max(ans, times);
		//	cout<<loop<<endl;
		}
		else if(ch == 'E')
		{	
			if(sta.empty()) return rest(p, 1), false;
			P t = sta.top(); sta.pop(), loop--;
			if((M.find(t.first) == M.end()) || M[t.first] == false || loop < 0)
				return rest(p, 0), false;
			M[t.first] = false;
			if(t.second == 1) times--;
			else if(t.second == 2) flag--;
		}
	}
	if(!sta.empty()) {cout<<"ERR"<<endl; return false;}
	else return true;
}

int main()
{
	freopen("p3952.in", "r", stdin);
	cin>>T;
	while(T--)
	{
		init();
		if(solve())
		{
			if(mode == false && ans == 0) cout<<"Yes"<<endl;
			else if(mode == true && ans == _times) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
	return 0;
}
