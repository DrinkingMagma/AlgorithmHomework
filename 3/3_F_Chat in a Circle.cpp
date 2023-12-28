#include <iostream>
#include <algorithm>
using namespace std;
const int MX = 2 * 1e5 + 5;
typedef long long ll;
ll a[MX];
int b[MX];

int cmp(ll a, ll b)
{
    return a > b;
}

int main()
{
    int N;
    ll sum = 0;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        b[i] = 0;
    }
    sort(a + 1, a + N + 1, cmp);

    sum += a[1];
    for (int i = 3, j = 2; i <= N; i++)
    {
        if (b[j] == 2)
            j++;

        sum += a[j];
        b[j]++;
    }

    cout << sum << endl;
}