#include <iostream>
#include <algorithm>
using namespace std;
struct task {
    int start;//任务开始时间 
    int last;//任务持续时间 
}t[10001];
int sch[10001]={0},f[10001];//sch[i]->时间为i时任务数量,f[i]->第i个工作时间开始到最后一个工作时间最大空闲时间 
//按开始时间从大到小排序 
bool cmp(task a,task b) {
    return a.start>b.start;
}
int main() {
    int T,n;//T表示工作时间,n表示任务数量
    cin >> T >> n;
    for(int i=1;i<=n;i++) {
        cin >> t[i].start >> t[i].last;
        sch[t[i].start]++;
    }
    sort(t+1,t+n+1,cmp);
	memset(f,-63,sizeof(f));
    int now;//从开始到现在所经历的任务编号 
    for(int i=T,now=1;i>=1;i--) {
        if(!sch[i]) f[i]=f[i+1]+1;//没有任务就将上一个任务开始时间加1
        else {
            //从sch[i]个任务中找一个任务，使f[i+这个任务持续时间]最大 
            for(int k=1;k<=sch[i];k++,now++) {
                f[i]=max(f[i],f[i+t[now].last]);
				//cout<<"i= "<<i<<" "<<f[i]<<endl;
            }
        } 
    }
    cout << f[1] << endl;
    return 0;
}
