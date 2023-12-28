// #include <iostream>
// #include <cstdio>
// #include <cstring>
// using namespace std;
// const int maxn = 1e5 + 10;
// int main()
// {
//     int n, U;
//     int a[maxn];
//     scanf("%d%d", &n, &U);
//     for (int i = 1; i <= n; i++)
//     {
//         scanf("%d", &a[i]);
//     }
//     double ans = -1;
//     for (int i = 2; i <= n - 1; i++)
//     {
//         if (a[i + 1] - a[i - 1] > U)
//             continue;
//         int l = i + 1, r = n;
//         while (l <= r)
//         {
//             int mid = l + r >> 1;
//             if (a[mid] - a[i - 1] <= U)
//                 l = mid + 1;
//             else
//                 r = mid - 1;
//         }
//         ans = max(ans, (1.0 * (a[r] - a[i]) / (a[r] - a[i - 1])));
//     }
//     if (ans < -0.5)
//         printf("-1\n");
//     else
//         printf("%.10f\n", ans);
//     return 0;
// }


#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n, U;
    cin >> n >> U;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    double ans = -1;

    for (int i = 2; i <= n - 1; ++i) {
        if (a[i + 1] - a[i - 1] <= U) {
            int l = i + 1, r = n;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (a[mid] - a[i - 1] <= U) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if (a[r] - a[i - 1] <= U) {
                ans = max(ans, static_cast<double>(a[r] - a[i]) / (a[r] - a[i - 1]));
            }
        }
    }

    if (ans < -0.5) {
        cout << "-1\n";
    } else {
        cout << fixed << setprecision(10) << ans << endl;
    }

    return 0;
}
