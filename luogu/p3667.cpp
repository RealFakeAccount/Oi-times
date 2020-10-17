#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 5e2 + 20;

int N, M;
char str[MAXN << 1][MAXN];

inline int getnum(char ch){
	switch (ch){
		case 'A': return 0;
		case 'T': return 1;
		case 'C': return 2;
		case 'G': return 3;
	}
}

namespace trie
{
	struct Node
	{
		bool ended;
		Node *ch[4];
		Node() : ended(false);
	}pool[MAXN << 2], *pit = pool, root;

	inline void newnode(){
		static int cnt = 1;
		if(cnt < (MAXN << 2)) return ++cnt, new(pit++) Node();
		return new Node();
	}

	Node *insert(Node *cur, char s[], int p){
		if(!cur) cur = newnode();
		if(p == M) return cur->ended = true, cur;
		cur->ch[getnum(s[p])] = insert(cur->ch[getnum(s[p])], s, p + 1);
		return cur;
	}

	bool query(Node *cur, char s[], int p){
		if(!cur) return false;
		if(p == M) return cur->ended;
		return query(cur->ch[getnum(s[p])], s, p + 1);
	}
}

bool check(int x){
	for(int l = 1; l <= (M - x + 1); l++){
		int r = l + x - 1;
		for(int i = 1; i <= N; i++)
	}
}

int main()
{
	cin>>N>>M;
	for(int i = 1; i <= (N << 1); i++) scanf(" %s", str[i] + 1);

	int l = 0, r = M;
	while(l < r){
		int mid = (l + r) >> 1;
		if(check(mid)) l = mid + 1;
		else r = mid;
	} 
	cout<<l<<endl;
	return 0;
}