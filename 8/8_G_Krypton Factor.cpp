// #include <cstdio>
// #include <cstring>
// #include <cstdlib>
// #include <cctype>
// #include <cmath>
// #include <iostream>
// #include <sstream>
// #include <iterator>
// #include <algorithm>
// #include <string>
// #include <vector>
// #include <set>
// #include <map>
// #include <stack>
// #include <deque>
// #include <queue>
// #include <list>
// #define Min(a, b) ((a < b) ? a : b)
// #define Max(a, b) ((a < b) ? b : a)
// typedef long long ll;
// typedef unsigned long long llu;
// const int INT_INF = 0x3f3f3f3f;
// const int INT_M_INF = 0x7f7f7f7f;
// const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
// const ll LL_M_INF = 0x7f7f7f7f7f7f7f7f;
// const int dr[] = {0, 0, -1, 1, -1, -1, 1, 1};
// const int dc[] = {-1, 1, 0, 0, -1, 1, -1, 1};
// const int MOD = 1e9 + 7;
// const double pi = acos(-1.0);
// const double eps = 1e-8;
// const int MAXN = 100 + 10;
// const int MAXT = 10000 + 10;
// using namespace std;
// int n, L;
// int ans[MAXN];
// int cnt;
// int dfs(int cur)
// {
//     if (cnt++ == n)
//     { // cnt为当前为第几串
//         for (int i = 0; i < cur; ++i)
//         {
//             if (i && (i % 64 == 0))
//                 printf("\n");
//             else if (i && (i % 4 == 0))
//                 printf(" ");
//             printf("%c", 'A' + ans[i]);
//         }
//         printf("\n");
//         printf("%d\n", cur);
//         return 0;
//     }
//     else
//     {
//         for (int i = 0; i < L; ++i)
//         {
//             ans[cur] = i;
//             bool ok = true;
//             for (int j = 1; j * 2 <= cur + 1; ++j)
//             { // cur+1为当前串的长度,检查后缀最多只用检查到（cur+1）/2,因为再往前检查，检查的前串短于后串，没必要检查
//                 bool flag = true;
//                 for (int k = 0; k < j; ++k)
//                 {
//                     if (ans[cur - k] != ans[cur - k - j])
//                     {
//                         flag = false;
//                         break;
//                     }
//                 }
//                 if (flag)
//                 { // 方案不合法
//                     ok = false;
//                     break;
//                 }
//             }
//             if (ok)
//             { // 方案合法继续递归
//                 if (!dfs(cur + 1))
//                     return 0; // 已经找到解，退出所有递归
//             }
//         }
//         return 1;
//     }
// }
// int main()
// {
//     while (scanf("%d%d", &n, &L) == 2)
//     {
//         if (!n && !L)
//             return 0;
//         cnt = 0;
//         memset(ans, 0, sizeof ans);
//         dfs(0);
//     }
//     return 0;
// }

#include <cstdio>
#include <cstring>

int n, L;
int ans[110];
int cnt;

int dfs(int cur) {
    if (cnt++ == n) { // cnt为当前为第几串
        for (int i = 0; i < cur; ++i) {
            if (i && (i % 64 == 0))
                printf("\n");
            else if (i && (i % 4 == 0))
                printf(" ");
            printf("%c", 'A' + ans[i]);
        }
        printf("\n");
        printf("%d\n", cur);
        return 0;
    } else {
        for (int i = 0; i < L; ++i) {
            ans[cur] = i;
            bool ok = true;
            for (int j = 1; j * 2 <= cur + 1; ++j) { // cur+1为当前串的长度,检查后缀最多只用检查到（cur+1）/2,因为再往前检查，检查的前串短于后串，没必要检查
                bool flag = true;
                for (int k = 0; k < j; ++k) {
                    if (ans[cur - k] != ans[cur - k - j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) { // 方案不合法
                    ok = false;
                    break;
                }
            }
            if (ok) { // 方案合法继续递归
                if (!dfs(cur + 1))
                    return 0; // 已经找到解，退出所有递归
            }
        }
        return 1;
    }
}

int main() {
    while (scanf("%d%d", &n, &L) == 2) {
        if (!n && !L)
            return 0;
        cnt = 0;
        memset(ans, 0, sizeof ans);
        dfs(0);
    }
    return 0;
}
