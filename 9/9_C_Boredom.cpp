#include <iostream>
using namespace std;
const int N = 1e5 + 10;
long long dp[N][3];
long long m[N], ma = 0;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long long a;
        cin >> a;
        m[a]++;
        ma = max(ma, a);
    }
    for (int i = 1; i <= ma; i++)
    {
        dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + (long long)m[i] * i;
        dp[i][2] = dp[i - 1][1];
    }
    cout << max(dp[ma][0], max(dp[ma][1], dp[ma][2]));
}