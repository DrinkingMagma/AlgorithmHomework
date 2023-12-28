#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn = 1010;
const int mod = 1e9 + 7;
typedef long long LL;
using namespace std;
LL dp[maxn][maxn];
int m, n;
int a[maxn], b[maxn];
int main()
{
    while (scanf("%d%d", &n, &m) != -1)
    {
        memset(dp, 0, sizeof(dp));
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int j = 1; j <= m; j++)
            scanf("%d", &b[j]);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i] == b[j])
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + 1) % mod;
                else
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]) % mod;
            }
        }
        LL ans = dp[n][m];
        while (ans > mod)
            ans -= mod;
        if (ans < 0)
            ans += mod;
        printf("%I64d\n", ans);
    }
    return 0;
}