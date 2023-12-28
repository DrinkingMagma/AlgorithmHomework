 
// #include <iostream>
// #include <stdio.h>
// #include <algorithm>
// #include <cmath>
// #include <math.h>
// #include <cstring>
// #include <string>
// #include <queue>
// #include <deque>
// #include <stack>
// #include <stdlib.h>
// #include <list>
// #include <map>
// #include <utility>
// #include <set>
// #include <bitset>
// #include <vector>
// #define pi acos(-1.0)
// #define inf 0x3f3f3f3f
// #define ll long long
// #define linf 0x3f3f3f3f3f3f3f3fLL
// using namespace std;
// const int N = 1e6+5;
// const ll mod = 1e9+7;
// const ll INF = 1e18;
// struct edge{
//     int v,w,next;
// }e[N];
// int head[N];
// int cnt=0;
// void add(int u,int v)//建立一棵树
// {
//     e[cnt].v=v;
//     e[cnt].w=1;
//     e[cnt].next=head[u];
//     head[u]=cnt++;
// }
// int cnt1[N],cnt2[N];//标记数组
// void dfs(int u,int t,int p[])//深搜加标记
// {
//     if(p[u])
//         return ;
//     p[u]=t;
//     for(int i=head[u];~i;i=e[i].next)
//     {
//         dfs(e[i].v,t+1,p);
//     }
// }
// int main()
// {
 
//     int n;
//     while(scanf("%d",&n)!=EOF)
//     {
//         cnt=0;
//         memset(head,-1,sizeof(head));
//         for(int i=1;i<n;i++)
//         {
//             int a,b;
//             scanf("%d%d",&a,&b);
//             add(a,b);
//             add(b,a);
//         }
//         dfs(1,1,cnt1);
//         dfs(n,1,cnt2);
//         int ans=0;
//         for(int i=1;i<=n;i++)//看看哪个先走到这个节点
//         {
//             if(cnt1[i]<=cnt2[i])
//                 ans++;
//             else
//                 ans--;
 
//         }
//         if(ans>0)
//             printf("Fennec\n");
//         else
//             printf("Snuke\n");
// }
 
 
//     return 0;
// }


#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e6 + 5;

struct Edge {
    int v, next;
};

int head[N];
Edge edges[N];
int cnt = 0;

void add(int u, int v) {
    edges[cnt] = {v, head[u]};
    head[u] = cnt++;
}

int cnt1[N], cnt2[N];

void dfs(int u, int t, int p[]) {
    if (p[u])
        return;
    p[u] = t;
    for (int i = head[u]; ~i; i = edges[i].next) {
        dfs(edges[i].v, t + 1, p);
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        cnt = 0;
        memset(head, -1, sizeof(head));
        for (int i = 1; i < n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            add(a, b);
            add(b, a);
        }
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        dfs(1, 1, cnt1);
        dfs(n, 1, cnt2);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt1[i] <= cnt2[i])
                ans++;
            else
                ans--;
        }
        if (ans > 0)
            printf("Fennec\n");
        else
            printf("Snuke\n");
    }
    return 0;
}
