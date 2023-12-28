// #include <bits/stdc++.h>

// using namespace std;

// typedef long long ll;
// const int N = 4e5 + 10;
// ll a[N], p[N];
// ll s[N];
// ll ans = 0;
// int main()
// {
// 	ll n, x;
// 	cin >> n >> x;
// 	for (int i = 1; i <= n; i++)
// 	{
// 		cin >> a[i];
// 		a[n + i] = a[i];
// 		p[i] = p[i - 1] + a[i];
// 		s[i] = s[i - 1] + (1 + a[i]) * a[i] / 2;
// 	}
// 	for (int i = n + 1; i <= 2 * n; i++)
// 	{
// 		p[i] = p[i - 1] + a[i];
// 		s[i] = s[i - 1] + (a[i] + 1) * a[i] / 2;
// 	}
// 	n *= 2;
// 	for (int i = 1; i <= n; i++)
// 	{
// 		if (p[i] >= x)
// 		{
// 			ll t = lower_bound(p + 1, p + n + 1, p[i] - x) - p;
// 			ll res = s[i] - s[t];
// 			ll num = x - (p[i] - p[t]);
// 			res += num * (a[t] + a[t] - num + 1) / 2;
// 			ans = max(res, ans);
// 		}
// 	}
// 	cout << ans << endl;
// 	return 0;
// }

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 4e5 + 10;
ll a[N], p[N], s[N];
ll ans = 0;

int main() {
    ll n, x;
    cin >> n >> x;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[n + i] = a[i];
    }

    n *= 2;

    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + a[i];
        s[i] = s[i - 1] + (1 + a[i]) * a[i] / 2;
    }

    for (int i = 1; i <= n; i++) {
        if (p[i] >= x) {
            int t = lower_bound(p + 1, p + n + 1, p[i] - x) - p;
            ll res = s[i] - s[t];

            if (p[i] - p[t] < x) {
                ll num = x - (p[i] - p[t]);
                res += num * (a[t] + a[t] - num + 1) / 2;
            }

            ans = max(res, ans);
        }
    }

    cout << ans << endl;
    return 0;
}
