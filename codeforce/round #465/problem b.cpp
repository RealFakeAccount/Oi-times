#include <bits/stdc++.h>
using namespace std;

pair<int,int> pos;

int kingdom(pair<int,int> In)//1.y=x;2.k1;3.k2
{
	if(In.first>In.second)
		return 2;
	if(In.first<In.second)
		return 3;
	else
		return 1;
}

int main()
{
	string In;int N,nowk,cost;

	cin>>N>>In;
	pos=make_pair(0,0);nowk=1,cost=-1;
	for(int i=0;i<(int)In.length();i++)
	{
		if(In[i]=='U')
			pos.second++;
		else pos.first++;
		int con=kingdom(pos);
		//cout<<"pos: "<<pos.first<<" "<<pos.second<<endl;
		
		if(con==1)
			continue;
		if(con!=nowk)
		{
			cost++;
			nowk=con;
		}
		//cout<<"cost: "<<cost<<endl;
	}
	cout<<cost<<endl;
	return 0;
}