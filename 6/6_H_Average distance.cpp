// #include<iostream>
// #include<cstdio>
// #include<cstring>
// #include<vector>
// #include<algorithm>
// using namespace std;
// typedef long long ll;
// const int maxn=1e5+10;
// struct node{
//     int v;
//     ll w;
// }now;
// vector<node>v[maxn];
// int vis[maxn];
// int n,a,b;
// ll w,ans,t,son[maxn];
// void dfs(int x)
// {
//     vis[x]=1;
//     son[x]=1;
//     for(int i=0;i<v[x].size();i++)
//     {
//         node aa=v[x][i];
//         ll len=aa.w;
//         int to=aa.v;
//         if(vis[to])
//             continue;
//         dfs(to);
//         son[x]+=son[to];
//         ans+=len*(n-son[to])*son[to]; //注意2：这里一定要写son[to]而不是son[x] 写son[x]会导致边和其两边的点数不匹配。
//     //    cout<<x<<" "<<to<<endl;
//        // cout<<ans<<endl;
//     }
// }
// int main()
// {
//     int casen;
//     cin>>casen;
//     while(casen--)
//     {
//         ans=0;
//         memset(son,0,sizeof(son));
//         memset(vis,0,sizeof(vis));
//         scanf("%d",&n);
//         for(int i=0;i<=n;i++)
//             v[i].clear();
//         for(int i=1;i<n;i++)
//         {
//             scanf("%d%d%lld",&a,&b,&w);
//             now.v=b;
//             now.w=w;
//             v[a].push_back(now);
//             now.v=a;                //注意1：双向边对于该边的两个端点都要标记权值为边的值，这样不管先遍历到哪个节点，这个节点的权值就是该点和其下一个点之间的边的权值。
//             v[b].push_back(now);
//         }
//         dfs(0);
//         t=(n-1)*n/2;
//         printf("%.11f\n",(double)ans/(double)t);//注意3： 题目好坑啊，要求的误差在10-6 但是样例给的只是小数点后一位。
//     }
// }


#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;

struct Node {
    int v;
    ll w;
};

vector<Node> v[maxn];
int vis[maxn];
int n, a, b;
ll w, ans, t, son[maxn];

void dfs(int x) {
    vis[x] = 1;
    son[x] = 1;
    for (int i = 0; i < v[x].size(); i++) {
        Node aa = v[x][i];
        ll len = aa.w;
        int to = aa.v;
        if (vis[to]) {
            continue;
        }
        dfs(to);
        son[x] += son[to];
        ans += len * (n - son[to]) * son[to];
    }
}

int main() {
    int casen;
    cin >> casen;
    while (casen--) {
        ans = 0;
        memset(son, 0, sizeof(son));
        memset(vis, 0, sizeof(vis));
        scanf("%d", &n);
        for (int i = 0; i <= n; i++) {
            v[i].clear();
        }
        for (int i = 1; i < n; i++) {
            scanf("%d%d%lld", &a, &b, &w);
            Node now;
            now.v = b;
            now.w = w;
            v[a].push_back(now);
            now.v = a;
            v[b].push_back(now);
        }
        dfs(0);
        t = (n - 1) * n / 2;
        printf("%.11f\n", (double)ans / (double)t);
    }
}
