#include"iostream"
#include"algorithm"
#include"cstdio"
#include"cstring"
#include"cmath"
#define memset(a,b) memset(a,b,sizeof(a))
#define MX 10000 + 50
using namespace std;
int maxx,n,m,a[MX];
 
bool cmp(int x,int y) {
    return x>y;
}
 
void dfs(int x,int sum,int num) {
    if(sum>=m) {
        maxx=max(maxx,num); //如果花掉的硬币值已经够坐车了，更新最大花掉的硬币数
        return ;
    }
    if(x==n)return;  //如果已经查询了所有的硬币返回。
    dfs(x+1,sum+a[x],num+1);  //递归下去 搜索取下一个硬币的情况
    dfs(x+1,sum,num);        //搜索不取下一个硬币的情况
}
 
int main() {
    int T,num;
    cin>>T;
    while(T--) {
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++) {
            scanf("%d",&a[i]);
        }
        maxx=0;
        sort(a,a+n,cmp);  //按照硬币的枝排序；
        dfs(0,0,0);
        printf("%d\n",maxx);
    }
    return 0;
}