#include <bits/stdc++.h>
using namespace std;
typedef double D;

pair<int,int> fafa,flat;
pair<long double,long double>ans;
int R;



bool outside(pair<int,int>a,pair<int,int>b,int R)
{
	if( ( (abs(a.first-b.first)) * (abs(a.first-b.first) ) )
	 +( (abs(a.second-b.second)) * (abs(a.second-b.second)) ) >= R*R)
		return true;
	return false;
}

int main()
{
	cin>>R>>flat.first>>flat.second>>fafa.first>>fafa.second;
	if(outside(flat,fafa,R))
		cout<<flat.first<<" "<<flat.second<<" "<<R<<endl;
	else
	{
		long double r=sqrtl( (  (abs(flat.first-fafa.first))*(abs(flat.first-fafa.first) ) ) 
			+( (abs(flat.second-fafa.second)) * (abs(flat.second-fafa.second)) ) );
		long double l=(r+R)/2;
		cout.setf(ios::fixed);
		cout<<setprecision(8)<<fafa.first/l*r<<" "<<fafa.second/l*r<<" "<<r<<endl;

	}
	return 0;
}