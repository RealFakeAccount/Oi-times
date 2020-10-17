#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <algorithm>
using namespace std;
struct node
{
	int t;
	struct node *next;
};
int main()
{
int n,k;
node*p,*head=0;
cin>>n;
for(int i=1;i<=n;i++)
{
	cin>>k;
	p=new node;
	p->t=k;
	p->next=head;
	head=p;
}
p=head;
while(p)
{
	cout<<p->t<<endl;
	p=p->next;
	
}
return 0;
}