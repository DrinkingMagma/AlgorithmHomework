#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 105;
vector<int> vec[maxn];
int dp[maxn];
void dfs(int x, int pre)
{
    for (int i = 0; i < vec[x].size(); i++)
    {
        if (vec[x][i] == pre)
            continue;
        dfs(vec[x][i], x);
        dp[0] = max(dp[0], dp[x] + dp[vec[x][i]] + 1);
        dp[x] = max(dp[x], dp[vec[x][i]] + 1);
    }
    return;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &m);
        for (int j = 1; j < m; j++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        memset(dp, 0, sizeof(dp));
        dfs(1, 0);
        for (int j = 1; j <= m; j++)
            vec[j].clear();
        ans += dp[0];
    }
    printf("%d\n", ans);
    return 0;
}