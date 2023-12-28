// #include <stdio.h>
// #include <math.h>
// #include <string.h>
// #include <algorithm>
// using namespace std;
// int main()
// {
//     long long n, m;
//     while (~scanf("%lld%lld", &n, &m))
//     {
//         m += 1;
//         long long p = (long long)1 << n, count = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (m > p / 2)
//                 p /= 2,
//                     m -= p;
//             else if (m <= p / 2)
//             {
//                 count++;
//                 p /= 2;
//             }
//         }
//         if (count & 1)
//             printf("blue\n");
//         else
//             printf("red\n");
//     }
// }


#include <iostream>
using namespace std;

int main() {
    long long n, m;
    while (cin >> n >> m) {
        m += 1;
        long long p = (1LL << n), count = 0;

        for (int i = 0; i < n; ++i) {
            if (m > p / 2) {
                p /= 2;
                m -= p;
            } else if (m <= p / 2) {
                count++;
                p /= 2;
            }
        }

        if (count & 1) {
            cout << "blue\n";
        } else {
            cout << "red\n";
        }
    }

    return 0;
}
