// /*
// dp[i][j]=dp[i的所有因子][j-1]的和；
// dp[i][j]表示最高位为i，长度为j时的个数
// */

// #include <algorithm>
// #include <iostream>
// #include <cstdio>
// #include <string>
// #include <cstring>
// using namespace std;
// const int Mod = 1e9 + 7;
// const int M = 2001 + 10;
// long long dp[M][M];
// int main()
// {
//     // freopen("in.txt","r",stdin);
//     // freopen("out.txt","w",stdout);
//     int n, k, i, j;
//     while (cin >> n >> k)
//     {
//         memset(dp, 0, sizeof(dp));
//         dp[1][0] = 1;
//         for (i = 1; i <= n; i++)
//         {
//             for (j = 1; j <= k; j++)
//             {
//                 for (int ii = 1; ii * ii <= i; ii++)
//                 { // 求数i的所有因子，根号n的复杂度，
//                     if (i % ii == 0)
//                     { // 如果数ii是i的因子，那么i/ii也是i的因子。不优化会超时
//                         dp[i][j] = (dp[i][j] + dp[ii][j - 1]) % Mod;
//                         if (ii != i / ii)
//                             dp[i][j] = (dp[i][j] + dp[i / ii][j - 1]) % Mod;
//                     }
//                 }
//             }
//         }
//         long long res = 0;
//         for (i = 1; i <= n; i++)
//             res += dp[i][k] % Mod;
//         cout << res % Mod << endl;
//     }
//     return 0;
// }


#include <iostream>
#include <cstring>
using namespace std;

const int Mod = 1e9 + 7;
const int MX = 2001 + 10;
long long dp[MX][MX];

int main()
{
    int n, k;
    cin >> n >> k;

    memset(dp, 0, sizeof(dp));
    dp[1][0] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            for(int ii = 1; ii * ii <= i; ii++)
            {
                if(i % ii == 0)
                {
                    dp[i][j] = (dp[i][j] + dp[ii][j - 1]) % Mod;
                    if(ii != i / ii)
                        dp[i][j] = (dp[i][j] + dp[i / ii][j - 1]) % Mod;
                }
            }
        }
    }

    long long result = 0;
    for(int i = 1; i <= n; i++)
        result += dp[i][k] % Mod;

    cout << result % Mod << endl;

   return 0;
}
