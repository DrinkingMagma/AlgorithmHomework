// #include <bits/stdc++.h>
// #define IOS                          \
//     ;                                \
//     {                                \
//         ios::sync_with_stdio(false); \
//         cin.tie(0);                  \
//         cout.tie(0);                 \
//     }
// const int N = 10;
// typedef long long ll;
// using namespace std;
// ll a[N];

// int main()
// {
//     IOS; // 提高执行效率
//     int n;
//     cin >> n;
//     while (n--)
//     {
//         ll a0, a1, a2, b0, b1, b2, sum = 0;
//         cin >> a0 >> a1 >> a2 >> b0 >> b1 >> b2;

//         ll t = min(a2, b1);
//         a2 -= t;
//         b1 -= t;
//         sum += 2 * t;

//         ll x = a0 + a2 - b2;
//         if (x > 0)
//             x = 0;
//         sum += 2 * x;

//         cout << sum << endl;
//     }
//     return 0;
// }

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        long long result = 0;
        long long a0, a1, a2, b0, b1, b2, sum = 0;
        cin >> a0 >> a1 >> a2 >> b0 >> b1 >> b2;

        int t = min(a2, b1);
        a2 -= t;
        b1 -= t;
        result += t << 1;

        t = min(a0, b2);
        a0 -= t;
        b2 -= t;

        if(b2 - a2 > 0 && a1 - b0 - b1 > 0)
        {
            t = min(b2 - a2, a1 - b0 - b1);
            result -= t << 1;
        }

        cout << result << endl;
    }

   return 0;
}
