#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct node
{
    int w,h,pos;
}l[5005];

int dp[5005],pre[5005];

bool cmp(node a,node b)
{
    return a.w < b.w;
}

void Print(int x)
{
    if(x == -1) return ;
    Print(pre[x]);
    
    printf("%d ",l[x].pos);
}

int main()
{
    int n,w,h,len = 0;
    cin >> n >> w >> h;
    
    int a,b,ans;
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a,&b);
        if(a > w && b > h){
            l[len].w = a;
            l[len].h = b;
            l[len++].pos = i;
            ans = i;
        }
    }
    
    if(len == 0) cout << 0 << endl;
    else if(len == 1){
        cout << 1 << endl;
        cout << ans << endl;
    }
    else{
        sort(l,l+len,cmp);
        memset(pre,-1,sizeof pre);
        
        for(int i = 0;i < len ;i++){
            dp[i] = 1;
            for(int j = 0;j<i;j++){
                if(l[i].h > l[j].h && l[i].w > l[j].w && dp[i] < dp[j] + 1){   //注意w即使排完序也可能相等，所以也要判断
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
        }
        int ans=0,in;
        for(int i = 0;i < len; i++){
            if(dp[i] > ans){
                 ans = dp[i];
                 in = i;
            }
        }
        cout << ans << endl;
        Print(in);
    }
    
    return 0;
}
