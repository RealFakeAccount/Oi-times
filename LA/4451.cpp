#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int INF = 0x3f3f3f3f;
const int UP = 0;
const int FLOOR = 1;
const int DOWN = 2;
const int MAXM = 15;

int deck[MAXM << 1], n;
char s[10],c;

inline int getscore(int c1, int c2, int c3)
{
	int tmp = (c1 > 0) + (c2 > 0) + (c3 > 0);
	if(tmp > 1) return (abs(c1) + abs(c2) + abs(c3));
	else return -(abs(c1) + abs(c2) + abs(c3));
}

struct State
{
	int card[8], type[8];
	int hold[2];
	int pos;
	int score;

	State()
	{
		for(int i = 0; i < 8; i++)
		{
			card[i] = deck[i];
			type[i] = i % 2 == 0 ? UP : DOWN;
			hold[0] = hold[1] = score = 0;
			pos = 8;
		}
	}	

	bool isfinal()
	{
		if(pos == 2 * n)
		{
			score += hold[0] + hold[1];
			hold[0] = hold[1] = 0;
			return true;
		}
		return false;
	}

	State child() const{
		State s;
		memcpy(&s, this, sizeof(s));
		s.pos = pos + 1;
		return s;
	}

	void expand(int player, vector<State> &ret) const{
		int cur = deck[pos];

		if(hold[player] == 0)
		{
			State s = child();
			s.hold[player] = cur;
			ret.push_back(s);
		}

		if(true)
		{
			for(int i = 0; i < 7; i++)
				if(type[i] == DOWN && type[i + 1] == UP)
				{
					State s = child();
					s.score += getscore(card[i], card[i + 1], cur);
					s.type[i] = s.type[i + 1] = FLOOR;
					s.card[i] = s.card[i + 1] = cur;
					ret.push_back(s);

					if(hold[player] != 0)
					{
						State s = child();
						s.score += getscore(card[i], card[i + 1], hold[player]);
						s.type[i] = s.type[i + 1] = FLOOR;
						s.card[i] = s.card[i + 1] = cur;
						ret.push_back(s);
					}
				}
		}

		if(hold[player] != 0)
		{
			for(int i = 0; i < 7; i++)
				if(type[i] == FLOOR && type[i + 1] == FLOOR
					&& card[i] == card[i + 1])
				{
					State s = child();
					s.score += getscore(card[i], hold[player], cur);
					s.type[i] = UP; s.type[i + 1] = DOWN;
					s.card[i] = cur; s.card[i + 1] = hold[player]; s.hold[player] = 0;
					ret.push_back(s);
				}
		}
	}
};

int alphabeta(State &s, int player, int alpha, int beta) 
{
    if(s.isfinal()) return s.score;
    vector<State> children;
    s.expand(player, children);
    int n = children.size();
    for(int i = 0; i < n; ++i) {
        int v = alphabeta(children[i], player ^ 1, alpha, beta);
        if(!player) alpha = max(alpha, v);
        else beta = min(beta, v);
        if(beta <= alpha) break;
    }
    return !player ? alpha : beta;
}

int main() {
    int t = 0;
    while(scanf("%s", s) != EOF && *s != 'E') {
        scanf("%d", &n);
        for(int i = 0; i < 2 * n; ++i) {
            scanf("%d%c", &deck[i], &c);
            if(c == 'B') deck[i] = -deck[i];
        }
        int start = !(deck[0] > 0);
        State beg;
        int ans = alphabeta(beg, start, -INF, INF);
        printf("Case %d: ", ++t);
        if(s[0] == 'B') ans = -ans;
        if(ans == 0) puts("Axel and Birgit tie");
        else if(ans > 0) printf("%s wins %d\n", s, ans);
        else printf("%s loses %d\n", s, -ans);
    }
}