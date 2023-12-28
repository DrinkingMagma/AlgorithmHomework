// #include <cstdio>
// #include <cmath>
// #include <iostream>
// #include <cstring>
// #include <algorithm>
// #include <queue>
// #include <stack>
// #include <vector>
// #include <map>
// #include <numeric>
// #include <set>
// #include <string>
// #include <cctype>
// #include <sstream>
// #define INF 0x3f3f3f3f
// #define lson l, m, rt << 1
// #define rson m + 1, r, rt << 1 | 1
// using namespace std;
// typedef long long LL;
// typedef pair<LL, LL> P;
// const int maxn = 1e5 + 5;
// const int mod = 1e8 + 7;

// int n, fa[maxn];
// vector<int> G[maxn];
// double cnt = 0, sum = 0;
// void dfs(int x, int d, double ss)
// {
//     if (G[x].size() == 1 && x != 1)
//     {
//         sum += (d - 1) * ss;
//         return;
//     }
//     for (int i = 0; i < G[x].size(); i++)
//     {
//         int son = G[x][i];
//         if (son == fa[x])
//             continue;
//         fa[son] = x;
//         double sss;
//         if (x == 1)
//             sss = ss * 1.0 / (G[x].size());
//         else
//             sss = ss * 1.0 / (G[x].size() - 1);
//         dfs(son, d + 1, sss);
//     }
//     return;
// }
// int main()
// {
//     while (~scanf("%d", &n))
//     {
//         if (n == 1)
//         {
//             printf("0.000000000000000\n");
//             continue;
//         }
//         for (int i = 0; i <= n; i++)
//             G[i].clear();
//         cnt = 0;
//         sum = 0;
//         memset(fa, 0, sizeof(fa));
//         int u, v;
//         n--;
//         while (n--)
//         {
//             scanf("%d%d", &u, &v);
//             G[u].push_back(v);
//             G[v].push_back(u);
//         }
//         dfs(1, 1, 1.0);
//         printf("%.15lf\n", sum);
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 5;

int n, fa[maxn];
vector<int> G[maxn];
double cnt = 0, sum = 0;

void dfs(int x, int d, double ss)
{
    if (G[x].size() == 1 && x != 1)
    {
        sum += (d - 1) * ss;
        return;
    }

    for (int i = 0; i < G[x].size(); i++)
    {
        int son = G[x][i];
        if (son == fa[x])
            continue;
        fa[son] = x;
        double sss;
        if (x == 1)
            sss = ss * 1.0 / G[x].size();
        else
            sss = ss * 1.0 / (G[x].size() - 1);
        dfs(son, d + 1, sss);
    }
}

int main()
{
    while (cin >> n)
    {
        if (n == 1)
        {
            cout << "0.000000000000000" << endl;
            continue;
        }

        for (int i = 0; i <= n; i++)
            G[i].clear();

        cnt = 0;
        sum = 0;
        memset(fa, 0, sizeof(fa));
        int u, v;
        n--;

        while (n--)
        {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        dfs(1, 1, 1.0);
        cout.precision(15);
        cout << fixed << sum << endl;
    }

    return 0;
}
