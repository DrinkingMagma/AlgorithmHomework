// #include <bits/stdc++.h>

// using namespace std;

// typedef long long LL;

// const int N = 30;

// int tem[N], cnt, n, m;
// int g[N][N], c[N];
// bool st[N];

// void dfs(int u) {   //将所有连通块中的点存到tem数组
//     st[u] = 1;
//     tem[cnt ++] = u;
//     for (int i = 1; i <= n; i ++) {
//         if (!st[i] && g[i][u])  dfs(i);
//     }
// }

// bool check(int u, int j) {  //判断点u是否可以染成颜色j
//     for (int i = 1; i <= n; i ++) {
//         if (g[u][i] && c[i] == j)   return false;
//     }
//     return true;
// }

// void dfs(int u, int &res) {
//     if (u == cnt)   {
//         res ++; //枚举完所有点，方案数加1
//         return ;
//     }
//     for (int i = 1; i <= 3; i ++) {
//         if (check(tem[u], i)) {
//             c[tem[u]] = i;
//             dfs(u + 1, res);
//             c[tem[u]] = 0;  //tem[u]点的颜色归为0，避免对tem[0] ~ tem[u - 1]点染色产生干扰
//         }
//     }
// }

// int main(){
//     cin >> n >> m;
//     while (m --) {
//         int a, b;
//         cin >> a >> b;
//         g[a][b] = g[b][a] = 1;
//     }

//     LL ans = 1;
//     for (int i = 1; i <= n; i ++) {
//         if (!st[i]) {
//             cnt = 0;    //重置tem数组元素的个数
//             dfs(i);     //获得连所有通块中的点
//             int t = 0;  //记录连通块染色的方案数
//             dfs(0, t);  //计算染色方案数
//             ans = ans * t;  //不同连通块之间的方案数独立，答案是各连通块染色方案的乘积
//         }
//     }
//     cout << ans;
//     return 0;
// }

#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 30;

int tem[N], cnt, n, m;
int g[N][N], c[N];
bool st[N];

void dfs(int u) {
    st[u] = 1;
    tem[cnt ++] = u;
    for (int i = 1; i <= n; i ++) {
        if (!st[i] && g[i][u])  dfs(i);
    }
}

bool check(int u, int j) {
    for (int i = 1; i <= n; i ++) {
        if (g[u][i] && c[i] == j)   return false;
    }
    return true;
}

void dfs(int u, int &res) {
    if (u == cnt)   {
        res ++;
        return ;
    }
    for (int i = 1; i <= 3; i ++) {
        if (check(tem[u], i)) {
            c[tem[u]] = i;
            dfs(u + 1, res);
            c[tem[u]] = 0;
        }
    }
}

int main(){
    cin >> n >> m;
    while (m --) {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }

    LL ans = 1;
    for (int i = 1; i <= n; i ++) {
        if (!st[i]) {
            cnt = 0;
            dfs(i);
            int t = 0;
            dfs(0, t);
            ans = ans * t;
        }
    }
    cout << ans;
    return 0;
}

