// #include <iostream>
// #include <cstdio>
// using namespace std;
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     while (n--)
//     {
//         int z;
//         long long int m, sum = 0;
//         scanf("%lld", &m);
//         scanf("%d", &z);
//         while (z--)
//         {
//             long long int a, b;
//             scanf("%lld %lld", &a, &b);
//             long long int r = 1;
//             a = a % m;
//             while (b != 0)
//             {
//                 if (b % 2)
//                 {
//                     r = (r * a) % m;
//                 }
//                 a = (a * a) % m;
//                 b /= 2;
//             }
//             sum += r;
//         }
//         long long int answer = sum % m;
//         printf("%lld\n", answer);
//     }
//     return 0;
// }



#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        long long m, sum = 0;
        cin >> m;

        int z;
        cin >> z;

        while (z--) {
            long long a, b;
            cin >> a >> b;

            long long r = 1;
            a %= m;

            while (b != 0) {
                if (b % 2) {
                    r = (r * a) % m;
                }
                a = (a * a) % m;
                b /= 2;
            }
            sum = (sum + r) % m;
        }
        cout << sum << endl;
    }
    return 0;
}
