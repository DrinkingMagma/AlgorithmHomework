#include <iostream>
using namespace std;
typedef long long ll;
const int N = 2e5 + 100;
ll gcdd(ll a, ll b)
{
    if (b)
        while ((a %= b) && (b %= a))
            ;
    return a + b;
}
const int mod = 998244353;
ll t, n, m, a, b, c, x, k, cnt, ans, ant, sum, q, p, idx;
ll arr[N], brr[N], crr[N];
ll axx[2000][2000];
bool book[N];
char s[N];

int main()
{
    cin >> n;
    ant = 0;
    cnt = 0;
    ans = 0;
    ll zheng = 0, fu = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (x > 0)
        {
            ant++;
        }
        else
        {
            swap(ant, cnt);
            cnt++;
        }
        zheng += ant;
        fu += cnt;
    }
    cout << fu << ' ' << zheng;
}