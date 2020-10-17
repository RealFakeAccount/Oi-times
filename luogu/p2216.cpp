#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e2 + 10;
const int MAXM = 1e3 + 10;
inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch -'0', ch = getchar();
	return x;
}

int A, B, N;
int squ[MAXM][MAXM];
int fmn[MAXM][MAXM], fmx[MAXM][MAXM];//0->min, 1->max;
int qmin[MAXM], qmax[MAXM], lmin, lmax, rmin, rmax;

int main()
{
	cin>>A>>B>>N;
	for(int i = 1; i <= A; i++)
		for(int j = 1; j <= B; j++) 
			squ[i][j] = read();

	for(int i = 1; i <= A; i++){
		lmin = lmax = rmin = rmax = 1;
		qmin[1] = qmax[1] = 1;
		for(int j = 2; j <= B; j++){
			while(lmin <= rmin && squ[i][qmin[rmin]] >= squ[i][j]) --rmin;
			while(lmax <= rmax && squ[i][qmax[rmax]] <= squ[i][j]) --rmax;
			qmin[++rmin] = j;qmax[++rmax] = j;
			
			while((j - qmin[lmin] + 1) > N) ++lmin;
			while((j - qmax[lmax] + 1) > N) ++lmax;
			fmn[i][j] = squ[i][qmin[lmin]], fmx[i][j] = squ[i][qmax[lmax]];
		}
	}

	int ans = (1 << 29);
	for(int i = N; i <= B; i++){
		lmin = rmin = lmax = rmax = 1;
		qmin[1] = fmn[N][i], qmax[1] = fmx[N][i];
		for(int j = N; j <= A; j++){
			while(lmin <= rmin && fmn[qmin[rmin]] >= fmn[j]) --rmin;
			while(lmax <= rmax && fmx[qmax[rmax]] <= fmx[j]) --rmax;
			qmin[++rmin] = j, qmax[++rmax] = j;

			while((j - qmin[lmin] + 1) > N) ++lmin;
			while((j - qmax[lmax] + 1) > N) ++lmax;
			ans = min(ans, qmax[lmax] - qmin[lmin]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
